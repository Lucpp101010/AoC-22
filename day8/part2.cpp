#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string line;
    vector<string> a;
    while(getline(cin, line)){
        a.push_back(line);
    }
    int n = (int)a.size(), m = (int)a[0].size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int score = 1;
            for(int d = 0; d < 4; d++){
                int x = i, y = j;
                int cnt = 0;
                while(true){
                    x += dx[d];
                    y += dy[d];
                    if(x < 0 || x >= n || y < 0 || y >= m){
                        score *= cnt;
                        break;
                    }
                    else if(a[x][y] >= a[i][j]){
                        score *= (cnt+1);
                        break;
                    }
                    cnt++;
                }
            }
            ans = max(ans, score);
        }
    }
    cout << ans << "\n";
}