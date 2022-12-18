#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, -1, 0, 0, 0, 0}, dy = {0, 0, 1, -1, 0, 0}, dz = {0, 0, 0, 0, 1, -1};

int main(){
    int x, y, z;
    set<tuple<int, int, int>> mp;
    int ans = 0;
    while(EOF != scanf("%d,%d,%d", &x, &y, &z)){
        mp.emplace(x, y, z);
        for(int i = 0; i < 6; i++) ans += mp.count(make_tuple(x+dx[i], y+dy[i], z+dz[i]));
    }
    ans = 6*size(mp) - 2*ans;
    cout << ans << "\n";
}