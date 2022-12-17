#include <bits/stdc++.h>
using namespace std;
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

int main(){
    string wind;
    cin >> wind;
    vector<vector<bool>> state(10000, vector<bool>(9));
    for(int i = 0; i < 9; i++) state[0][i] = true;
    for(int i = 0; i < 10000; i++) state[i][0] = state[i][8] = true;

    int high = 0;
    int w = 0;
    for(int it = 0; it < 2022; it++){
        int r = it%5;
        auto check = [&](int x, int y, bool place = false){
            for(int i = 0; i < sz(rocks[r]); i++){
                for(int j = 0; j < sz(rocks[r][0]); j++){
                    if(rocks[r][sz(rocks[r])-1-i][j]){
                        if(state[y+i][x+j]) return false;
                        if(place) state[y+i][x+j] = true;
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
                high = max(high, y + sz(rocks[r])-1);
                break;
            }
        }
    }
    cout << high << "\n";
}