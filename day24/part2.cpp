#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tiii;
#define sz(x) (int)size(x)

vector<int> dx = {1, -1, 0, 0, 0}, dy = {0, 0, 1, -1, 0};
vector<string> v;
int w, h, lc;

int reduce(int x, int m){
    return (m+(x-1)%m)%m+1;
}

int bfs(int sx, int sy, int st, int gx, int gy){
    queue<tiii> q;
    vector<vector<vector<bool>>> vis(h+2, vector<vector<bool>>(w+2, vector<bool>(lc, false)));
    q.emplace(sy, sx, st);
    vis[sy][sx][st%lc] = true;
    while(!q.empty()){
        auto [y, x, t] = q.front();
        q.pop();
        if(x == gx && y == gy){
            return t;
        }
        for(int i = 0; i < 5; i++){
            int x2 = x+dx[i], y2 = y+dy[i], t2 = t+1;
            if(y2 < 0 || y2 >= h+2 || v[y2][x2] == '#' || vis[y2][x2][t2%lc]) continue;
            bool safe = true;
            if(v[y2][reduce(x2-t2, w)] == '>') safe = false;
            if(v[y2][reduce(x2+t2, w)] == '<') safe = false;
            if(v[reduce(y2-t2, h)][x2] == 'v') safe = false;
            if(v[reduce(y2+t2, h)][x2] == '^') safe = false;
            if(safe){
                vis[y2][x2][t2%lc] = true;
                q.emplace(y2, x2, t2);
            }
        }
    }
    assert(false);
}

int main(){
    string line;
    while(getline(cin, line)) v.push_back(line);
    w = sz(v[0])-2;
    h = sz(v)-2;
    lc = lcm(w, h);
    int t1 = bfs(1, 0, 0, w, h+1);
    int t2 = bfs(w, h+1, t1, 1, 0);
    int t3 = bfs(1, 0, t2, w, h+1);
    cout << t3 << "\n";
}