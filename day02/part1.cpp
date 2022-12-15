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
        int my = line[2]-'X';
        score += my+1;
        if(op == my) score += 3;
        if((my-op+3)%3 == 1) score += 6;
    }
    cout << score << "\n";
}