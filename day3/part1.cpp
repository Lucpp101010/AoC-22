#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char find_duplicate(string line){
    int n = (int)line.size();
    set<char> s;
    for(int i = 0; i < n/2; i++) s.insert(line[i]);
    for(int i = n/2; i < n; i++) if(s.count(line[i])) return line[i];
    assert(false);
}
int to_int(char c){
    if(c >= 'a') return c-'a'+1;
    else return c-'A'+27;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int ans = 0;
    string line;
    while(getline(cin, line)){
        ans += to_int(find_duplicate(line));
    }
    cout << ans << "\n";
}