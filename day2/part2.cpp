#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int score = 0;
    string line;
    while(getline(cin, line)){
        int op = line[0]-'A';
        int res = line[2]-'X';
        score += res*3 + 1+(op+res+2)%3;
    }
    cout << score << "\n";
}