#include <bits/stdc++.h>
using namespace std;

int sign(int x){
    if(x < 0) return -1;
    return x > 0 ? 1 : 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string line;
    vector<vector<bool>> v(200, vector<bool>(200));
    while(getline(cin, line)){
        stringstream ss(line);
        string useless;
        vector<pair<int, int>> p;
        do{
            int x, y; char comma;
            ss >> x >> comma >> y;
            p.emplace_back(x-400, y);

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
    int ans = 0;
    for(ans = 0;; ans++){
        int x = 100, y = 0;
        bool ok = true;
        while(true){
            while(y < 199 && !v[x][y+1]) y++;
            if(y == 199){
                ok = false;
                break;
            }
            if(!v[x-1][y+1]) x--;
            else if(!v[x+1][y+1]) x++;
            else{
                v[x][y] = true;
                break;
            }
        }
        if(!ok) break;
    }
    cout << ans << "\n";
}