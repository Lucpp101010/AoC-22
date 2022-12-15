#include <bits/stdc++.h>
using namespace std;

/*
The normal version also runs in less than 1 second, even without -O2.
However, we can find a faster solution which has a time complexity
of O(h * w) where h is the height and w is the width:
Let's model the cave as a directed graph: We connect (x, y) with
(x-1, y+1), (x, y+1) and (x+1, y+1) if those cells are empty. Then
the set of cells which will be filled by sand is equivalent to the
set of cells reachable from the source. That problem can be easily
solved using dfs or bfs.
*/ 

int sign(int x){
    if(x < 0) return -1;
    return x > 0 ? 1 : 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string line;
    vector<vector<bool>> v(400, vector<bool>(200));
    int bottom = 0;
    while(getline(cin, line)){
        stringstream ss(line);
        string useless;
        vector<pair<int, int>> p;
        do{
            int x, y; char comma;
            ss >> x >> comma >> y;
            bottom = max(bottom, y);
            p.emplace_back(x-300, y);

        }while(ss >> useless);
        for(int i = 1; i < (int)p.size(); i++){
            auto [x1, y1] = p[i-1];
            auto [x2, y2] = p[i];
            v[x1][y1] = true;
            while(x1 != x2 || y1 != y2){
                x1 += sign(x2-x1);
                y1 += sign(y2-y1);
                v[x1][y1] = true;
            }
        }
    }
    bottom += 2;
    for(int i = 0; i < 400; i++) v[i][bottom] = true;

    int ans = 0;
    queue<pair<int, int>> q;
    q.emplace(200, 0);
    while(!q.empty()){
        ans++;
        auto [x, y] = q.front();
        q.pop();
        for(int dx = -1; dx <= 1; dx++){
            int x2 = x+dx, y2 = y+1;
            if(!v[x2][y2]){
                v[x2][y2] = true;
                q.emplace(x2, y2);
            }
        }
    }
    cout << ans << "\n";
}