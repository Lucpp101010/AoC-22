#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int ans = 0;
    string line;
    while(getline(cin, line)){
        stringstream ss;
        ss << line;
        int a, b, c, d;
        char useless;
        ss >> a >> useless >> b >> useless >> c >> useless >> d;
        if(max(a, c) <= min(b, d)){
            ans++;
        }
    }
    cout << ans << "\n";
}