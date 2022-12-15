#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int to_int(char c){
    if(c >= 'a') return c-'a';
    else return c-'A'+26;
}
ll to_mask(string s){
    ll msk = 0;
    for(char c : s) msk |= (1ll << to_int(c));
    return msk;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int ans = 0;
    string line;
    while(getline(cin, line)){
        ll msk = to_mask(line);
        getline(cin, line);
        msk &= to_mask(line);
        getline(cin, line);
        msk &= to_mask(line);
        ans += 1+__builtin_ctzll(msk);
    }
    cout << ans << "\n";
}