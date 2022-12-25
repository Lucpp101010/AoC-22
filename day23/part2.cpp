#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define sz(x) (int)size(x)
const int inf = 1e6;

vector<int> dy = {-1, 1, 0, 0}, dx = {0, 0, -1, 1};
vector<vector<int>> chy = {{-1, -1, -1}, {1, 1, 1}, {-1, 0, 1}, {-1, 0, 1}};
vector<vector<int>> chx = {{-1, 0, 1}, {-1, 0, 1}, {-1, -1, -1}, {1, 1, 1}};

int main(){
    string line;
    vector<string> v;
    while(getline(cin, line)) v.push_back(line);
    set<pii> elves;
    for(int i = 0; i < sz(v); i++){
        for(int j = 0; j < sz(v[i]); j++){
            if(v[i][j] == '#') elves.emplace(i, j);
        }
    }
    for(int r = 0;; r++){
        map<pii, pii> prop;
        map<pii, int> cnt;
        bool end = true;
        for(auto [y, x] : elves){
            vector<bool> ok(4, true);
            for(int d = 0; d < 4; d++){
                for(int i = 0; i < 3; i++){
                    if(elves.count(make_pair(y+chy[d][i], x+chx[d][i]))) ok[d] = false;
                }
            }
            auto p = make_pair(y, x);
            if(ok[0] && ok[1] && ok[2] && ok[3]) prop[p] = p, cnt[p]++;
            else{
                end = false;
                if(!ok[0] && !ok[1] && !ok[2] && !ok[3]) prop[p] = p, cnt[p]++;
                else for(int i = 0; i < 4; i++){
                    int d = (r+i)%4;
                    if(ok[d]){
                        auto q = make_pair(y+dy[d], x+dx[d]);
                        prop[p] = q;
                        cnt[q]++;
                        break;
                    }
                }
            }
        }
        set<pii> elves2;
        for(auto p : elves){
            auto q = prop[p];
            if(cnt[q] == 1) elves2.insert(q);
            else elves2.insert(p);
        }
        elves = elves2;
        if(end){
            cout << r+1 << "\n";
            return 0;
        }
    }
}