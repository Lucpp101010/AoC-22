#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<char>> v;
    string line;
    while(getline(cin, line)) {
        if(line.size() < 4) break;
        if(v.empty()) v.resize((line.size()+1)/4);
        for(int i = 1; i < (int)line.size(); i += 4){
            if(line[i] != ' ') v[i/4].push_back(line[i]);
        }
    }
    for(int i = 0; i < (int)v.size(); i++) reverse(v[i].begin(), v[i].end());
    while(getline(cin, line)){
        stringstream ss;
        ss << line;
        string useless;
        int cnt, from, to;
        ss >> useless >> cnt >> useless >> from >> useless >> to;
        from--, to--;
        vector<char> temp;
        for(int i = 0; i < cnt; i++){
            temp.push_back(v[from].back());
            v[from].pop_back();
        }
        for(int i = cnt-1; i >= 0; i--) v[to].push_back(temp[i]);
    }
    string ans;
    for(int i = 0; i < (int)v.size(); i++) ans += v[i].back();
    cout << ans << "\n";
}