#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll NUM_IT = 1e12;
#define sz(x) (int)size(x)

vector<vector<vector<bool>>> rocks = {
    {
        {1, 1, 1, 1}
    },
    {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0},
    },
    {
        {0, 0, 1},
        {0, 0, 1},
        {1, 1, 1}
    },
    {
        {1},
        {1},
        {1},
        {1}
    },
    {
        {1, 1},
        {1, 1}
    }
};

typedef vector<vector<bool>> vvb;
typedef tuple<vvb, int, int> State;

int main(){
    string wind;
    cin >> wind;
    vvb a(1000, vector<bool>(9));
    for(int i = 0; i < 9; i++) a[0][i] = true;
    for(int i = 0; i < sz(a); i++) a[i][0] = a[i][8] = true;

    map<State, pair<int, ll>> memo;

    int high = 0;
    int w = 0;
    ll rem = 0;
    for(ll it = 0; it < NUM_IT; it++){
        int r = (int)(it%5);
        auto check = [&](int x, int y, bool place = false){
            for(int i = 0; i < sz(rocks[r]); i++){
                for(int j = 0; j < sz(rocks[r][0]); j++){
                    if(rocks[r][sz(rocks[r])-1-i][j]){
                        if(a[y+i][x+j]) return false;
                        if(place){
                            high = max(high, y+i);
                            a[y+i][x+j] = true;
                        }
                    }
                }
            }
            return true;
        };
        int x = 3, y = high+4;
        while(true){
            int dx = (wind[w] == '<') ? -1 : 1;
            w = (w+1)%sz(wind);
            if(check(x+dx, y)) x += dx;
            if(check(x, y-1)) y--;
            else{
                assert(check(x, y, true));
                break;
            }
        }

        int row = 0;
        for(int j = y; j < y+4; j++){
            bool ok = true;
            for(int i = 1; i < 8; i++) ok &= (a[j][i] | a[j+1][i]);
            if(ok) row = j;
        }
        high -= row;
        vvb b = a;
        for(int i = 1; i < 8; i++){
            for(int j = 1; j <= high; j++) b[j][i] = a[j+row][i];
            for(int j = high+1; j < sz(b); j++) b[j][i] = 0;
        }
        a = b;
        rem += row;

        State st = {a, r, w};
        if(memo.count(st)){
            auto [old_it, old_rem] = memo[st];
            ll len = it-old_it;
            ll h = rem-old_rem;
            ll take = (NUM_IT - it) / len;
            it += take * len;
            rem += take * h;
        }
        memo.emplace(st, make_pair(it, rem));
    }
    ll ans = high+rem;
    cout << ans << "\n";
}