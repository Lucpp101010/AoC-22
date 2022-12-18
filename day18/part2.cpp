#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 25;
vector<int> dx = {1, -1, 0, 0, 0, 0}, dy = {0, 0, 1, -1, 0, 0}, dz = {0, 0, 0, 0, 1, -1};
int state[MAX][MAX][MAX] = {};

void dfs(int x, int y, int z){
    if(min(x, min(y, z)) < 0 || max(x, max(y, z)) >= MAX) return;
    if(state[x][y][z] != 0) return;
    state[x][y][z] = 2;
    for(int i = 0; i < 6; i++) dfs(x+dx[i], y+dy[i], z+dz[i]);
}

int main(){
    int x, y, z;
    while(EOF != scanf("%d,%d,%d", &x, &y, &z)){
        x++, y++, z++; // They put 0 in the input...
        state[x][y][z] = 1;
    }
    dfs(0, 0, 0);
    int ans = 0;
    for(int x = 1; x < MAX-1; x++){
        for(int y = 1; y < MAX-1; y++){
            for(int z = 1; z < MAX-1; z++){
                if(state[x][y][z] == 1)
                for(int i = 0; i < 6; i++){
                    if(state[x+dx[i]][y+dy[i]][z+dz[i]] == 2) ans++;
                }
            }
        }
    }
    cout << ans << "\n";
}