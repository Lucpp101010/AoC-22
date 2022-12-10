#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> add;
    string cmd;
    while(cin >> cmd){
        add.push_back(0);
        if(cmd == "addx"){
            int x;
            cin >> x;
            add.push_back(x);
        }
    }
    int val = 1;
    for(int i = 0; i < (int)add.size(); i++){
        if(abs(val - (i%40)) <= 1) cout << '#';
        else cout << '.';
        if(i % 40 == 39) cout << '\n';
        val += add[i];
    }
}