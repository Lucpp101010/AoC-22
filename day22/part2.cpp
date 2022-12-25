#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tiii;
#define sz(x) (int)size(x)
constexpr int LEN = 50;

int sign(int x){
    if(x < 0) return -1;
    return x > 0 ? 1 : 0;
}

vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vector<vector<int>> sides = {
    {1, 2, 4, 3},
    {5, 2, 0, 3},
    {1, 5, 4, 0},
    {1, 0, 4, 5},
    {0, 2, 5, 3},
    {4, 2, 1, 3}
};

vector<string> v;
vector<vector<int>> side;
vector<int> rot(6);
vector<vector<pair<int, int>>> pos(6, vector<pair<int, int>>(4));

void dfs(int x, int y, int s){
    for(int i = 0; i < LEN; i++){
        for(int j = 0; j < LEN; j++){
            side[y+i][x+j] = s;
        }
    }
    pos[s] = {{x+LEN-1, y}, {x+LEN-1, y+LEN-1}, {x, y+LEN-1}, {x, y}};
    for(int d = 0; d < 4; d++){
        int x2 = x+LEN*dx[d], y2 = y+LEN*dy[d];
        if(y2 >= 0 && x2 >= 0 && y2 < sz(v) && x2 < sz(v[y2]) && v[y2][x2] != ' ' && side[y2][x2] == -1){
            int s2 = sides[s][(d+rot[s])%4];
            for(int r = 0; r < 4; r++){
                if(sides[s2][(r+d+2)%4] == s){
                    rot[s2] = r;
                    break;
                }
            }
            dfs(x2, y2, s2);
        }
    }
}

int main(){
    string line;
    while(getline(cin, line)){
        if(line.empty()) break;
        v.push_back(line);
    }
    side.assign(LEN*4, vector<int>(LEN*4, -1));
    int sx = -1;
    for(int x = 0; x < sz(v[0]); x++){
        if(v[0][x] != ' '){
            dfs(sx = x, 0, 0);
            break;
        }
    }
    vector<vector<vector<tiii>>> g;
    for(int i = 0; i < sz(v); i++){
        g.push_back(vector<vector<tiii>>(sz(v[i]), vector<tiii>(4, {-1, -1, -1})));
        for(int j = 0; j < sz(v[i]); j++){
            for(int d = 0; d < 4; d++){
                int x = j+dx[d], y = i+dy[d];
                if(y < 0 || y >= sz(v) || x < 0 || x >= sz(v[y]) || v[y][x] == ' ') continue;
                g[i][j][d] = {y, x, d};
            }
        }
    }
    for(int s = 0; s < 6; s++){
        for(int d = 0; d < 4; d++){
            int s2 = sides[s][(d+rot[s])%4];
            int d2 = 0;
            for(; d2 < 4; d2++){
                if(sides[s2][(d2+rot[s2])%4] == s) break;
            }
            assert(d2 != 4);
            auto [px1, py1] = pos[s][d];
            auto [px2, py2] = pos[s][(d+1)%4];
            auto [qx1, qy1] = pos[s2][(d2+1)%4];
            auto [qx2, qy2] = pos[s2][d2%4];
            for(int i = 0; i < LEN; i++){
                g[py1][px1][d]  = {qy1, qx1, (d2+2)%4};
                g[qy1][qx1][d2] = {py1, px1, (d+2)%4};
                px1 += sign(px2-px1);
                py1 += sign(py2-py1);
                qx1 += sign(qx2-qx1);
                qy1 += sign(qy2-qy1);
            }
        }
    }
    getline(cin, line);
    stringstream in(line);
    int x = sx, y = 0, dir = 0;
    while(true){
        int step;
        in >> step;
        for(int i = 0; i < step; i++){
            auto [ny, nx, nd] = g[y][x][dir];
            if(nx == -1 || v[ny][nx] != '.') break;
            x = nx, y = ny, dir = nd;
        }
        char c;
        if(!(in >> c)) break;
        if(c == 'L') dir = (dir+3)%4;
        else dir = (dir+1)%4;
    }
    cout << 1000*(y+1)+4*(x+1)+dir << "\n";
}