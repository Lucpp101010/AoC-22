#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) (int)size(x)

int to_int(char c){
    if(c == '=') return -2;
    if(c == '-') return -1;
    return c-'0';
}

ll from_snafu(string s){
    ll b = 1, y = 0;
    for(int i = sz(s)-1; i >= 0; i--){
        y += b * to_int(s[i]);
        b *= 5;
    }
    return y;
}

char to_char(int x){
    if(0 <= x && x < 3) return char('0'+x);
    if(x == 3) return '=';
    if(x == 4) return '-';
    assert(false);
}

string to_snafu(ll x){
    string s;
    while(x){
        int r = (int)(x%5);
        s += to_char(r);
        x /= 5;
        if(r >= 3) x++;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    ll ans = 0;
    string line;
    while(getline(cin, line)){
        ans += from_snafu(line);
    }
    cout << to_snafu(ans) << "\n";
}