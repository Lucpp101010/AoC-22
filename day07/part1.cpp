#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> tsize(1, -1);
vector<set<int>> g;
ll ans = 0;

void dfs(int u){
    if(tsize[u] != -1) return;
    tsize[u] = 0;
    for(int v : g[u]){
        dfs(v);
        tsize[u] += tsize[v];
    }
    if(tsize[u] <= 100000) ans += tsize[u];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string line;
    vector<string> st = {"/"};
    map<string, int> mp = {{"/", 0}};
    auto to_int = [&](string s){
        if(!mp.count(s)) {
            mp.emplace(s, (int)mp.size());
            tsize.push_back(-1);
            g.push_back(set<int>());
        }
        return mp[s];
    };
    while(getline(cin, line)){
        if(line[0] == '$'){
            if(line[2] == 'l') continue;
            string file = line.substr(5);
            if(file == "..") st.pop_back();
            else if(file == "/") st = {"/"};
            else{
                file = st.back()+"/"+file;
                int par = to_int(st.back());
                int child = to_int(file);
                g[par].insert(child);
                st.push_back(file);
            }
        }
        else{
            if(line[0] == 'd') continue;
            stringstream ss;
            ss << line;
            int siz; string file;
            ss >> siz >> file;
            file = st.back()+"/"+file;
            int par = to_int(st.back());
            int child = to_int(file);
            g[par].insert(child);
            tsize[child] = siz;
        }
    }
    dfs(0);
    cout << ans << "\n";
}