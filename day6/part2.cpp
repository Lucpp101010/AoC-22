#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    for(int i = 13; i < (int)s.size(); i++){
        set<char> check;
        for(int j = i-13; j <= i; j++) check.insert(s[j]);
        if(check.size() == 14){
            cout << i+1 << "\n";
            return 0;
        }
    }
}