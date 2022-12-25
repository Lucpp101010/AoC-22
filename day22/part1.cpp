#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)size(x)

vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

int main(){
    vector<string> v;
    string line;
    while(getline(cin, line)){
        if(line.empty()) break;
        v.push_back(line);
    }
    vector<vector<vector<pair<int, int>>>> g;
    int sx = -1, sy = -1;
    for(int i = 0; i < sz(v); i++){
        g.push_back(vector<vector<pair<int, int>>>(sz(v[i]), vector<pair<int, int>>(4, {-1, -1})));
        for(int j = 0; j < sz(v[i]); j++){
            if(v[i][j] == '.' && sx == -1) sx = j, sy = i;
            for(int d = 0; d < 4; d++){
                int x = j+dx[d], y = i+dy[d];
                if(y < 0 || y >= sz(v) || x < 0 || x >= sz(v[y]) || v[y][x] == ' '){
                    if(d == 0) x = 0;
                    if(d == 1) y = 0;
                    if(d == 2) x = sz(v[y])-1;
                    if(d == 3) y = sz(v)-1;
                    while(x >= sz(v[y]) || v[y][x] == ' '){
                        x += dx[d];
                        y += dy[d];
                    }
                }
                if(v[y][x] == '.') g[i][j][d] = {y, x};
            }
        }
    }
    getline(cin, line);
    stringstream in(line);
    int x = sx, y = sy, dir = 0;
    while(true){
        int step;
        in >> step;
        for(int i = 0; i < step; i++){
            auto [ny, nx] = g[y][x][dir];
            if(nx == -1) break;
            x = nx, y = ny;
        }
        char c;
        if(!(in >> c)) break;
        if(c == 'L') dir = (dir+3)%4;
        else dir = (dir+1)%4;
    }
    cout << 1000*(y+1)+4*(x+1)+dir << "\n";
}