#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll ans = 0;
    ll val = 0;
    string line;
    auto empty = [&](){
        ans = max(ans, val);
        val = 0;
    };
    while(getline(cin, line)){
        if(line[0] < '0' || line[0] > '9'){
            empty();
        }
        else{
            val += stol(line);
        }
    }
    empty();
    cout << ans << "\n";
}