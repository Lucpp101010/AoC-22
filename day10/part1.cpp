#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> add;
    string cmd;
    while(cin >> cmd){
        add.push_back(0);
        if(cmd == "addx"){
            ll x;
            cin >> x;
            add.push_back(x);
        }
    }
    ll ans = 0;
    ll val = 1;
    for(int i = 0; i < (int)add.size(); i++){
        val += add[i];
        if(i % 40 == 18) ans += (i+2)*val;
    }
    cout << ans << "\n";    
}