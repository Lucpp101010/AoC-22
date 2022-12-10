#include <bits/stdc++.h>
using namespace std;

map<char, int> dx = {{'L', -1}, {'R', 1}, {'D', 0}, {'U', 0}};
map<char, int> dy = {{'L', -0}, {'R', 0}, {'D', -1}, {'U', 1}};

int sign(int x){
    if(x < 0) return -1;
    return min(1, x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    set<pair<int, int>> s;
    int tx = 0, ty = 0, hx = 0, hy = 0;
    char dir;
    while(cin >> dir){
        int dist;
        cin >> dist;
        for(int i = 0; i < dist; i++){
            hx += dx[dir];
            hy += dy[dir];
            if(max(abs(hx-tx), abs(hy-ty)) > 1){
                tx += sign(hx-tx);
                ty += sign(hy-ty);
            }
            s.emplace(tx, ty);
        }
    }
    cout << (int)s.size() << "\n";
}