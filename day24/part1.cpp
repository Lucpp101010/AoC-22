#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tiii;
#define sz(x) (int)size(x)

vector<int> dx = {1, -1, 0, 0, 0}, dy = {0, 0, 1, -1, 0};

int main(){
    vector<string> v;
    string line;
    while(getline(cin, line)) v.push_back(line);
    int w = sz(v[0])-2, h = sz(v)-2;
    auto reduce = [&](int x, int m){
        return (m+(x-1)%m)%m+1;
    };
    queue<tiii> q;
    int lc = lcm(w, h);
    vector<vector<vector<bool>>> vis(h+2, vector<vector<bool>>(w+2, vector<bool>(lc, false)));
    q.emplace(0, 1, 0);
    vis[0][1][0] = true;
    while(!q.empty()){
        auto [y, x, t] = q.front();
        q.pop();
        if(x == w && y == h+1){
            cout << t << "\n";
            return 0;
        }
        for(int i = 0; i < 5; i++){
            int x2 = x+dx[i], y2 = y+dy[i], t2 = t+1;
            if(y2 < 0 || v[y2][x2] == '#' || vis[y2][x2][t2%lc]) continue;
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
}