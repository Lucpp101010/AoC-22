#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;

vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string line;
    vector<string> v;
    while(getline(cin, line)) v.push_back(line);
    int n = (int)v.size(), m = (int)v[0].size();
    vector<vector<int>> dist(n, vector<int>(m, inf));
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 'S'){
                v[i][j] = 'a';
            }
            if(v[i][j] == 'E'){
                dist[i][j] = 0;
                q.emplace(i, j);
                v[i][j] = 'z';
            }
        }
    }
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        if(v[x][y] == 'a'){
            cout << dist[x][y] << "\n";
            return 0;
        }
        for(int i = 0; i < 4; i++){
            int x2 = x+dx[i];
            int y2 = y+dy[i];
            if(x2 < 0 || n-1 < x2 || y2 < 0 || m-1 < y2) continue;
            if(v[x][y]-v[x2][y2] > 1) continue;
            if(dist[x2][y2] > dist[x][y]+1){
                dist[x2][y2] = dist[x][y]+1;
                q.emplace(x2, y2);
            }
        }
    }
}