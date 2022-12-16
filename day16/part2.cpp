#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)size(x)
const int inf = 1e8;

int start, n, k;
vector<vector<int>> g;
vector<int> flow;

void solve(){
    vector<int> add(1<<k);
    for(int msk = 0; msk < (1<<k); msk++){
        for(int i = 0; i < k; i++){
            if(msk & (1<<i)) add[msk] += flow[i];
        }
    }
    vector<vector<int>> dp(n*n, vector<int>(1<<k, -inf));
    dp[n*start + start][0] = 0;
    for(int it = 0; it < 26; it++){
        vector<vector<int>> dp2 = dp;
        auto vis = [&](int u, int e, int msk, int val){
            dp2[u*n+e][msk] = max(dp2[u*n+e][msk], val);
        };
        for(int verts = 0; verts < n*n; verts++){
            int u = verts/n, e = verts%n;
            for(int msk = 0; msk < (1<<k); msk++){
                int val = dp[verts][msk] + add[msk];
                for(int v : g[u]) vis(v, e, msk, val);
                if(u < k) vis(u, e, msk|(1<<u), val);
            }
        }
        dp = dp2;
        for(int verts = 0; verts < n*n; verts++){
            int u = verts/n, e = verts%n;
            for(int msk = 0; msk < (1<<k); msk++){
                int val = dp[verts][msk];
                for(int f : g[e]) vis(u, f, msk, val);
                if(e < k) vis(u, e, msk|(1<<e), val);
            }
        }
        dp = dp2;
    }
    int ans = 0;
    for(int u = 0; u < n; u++) ans = max(ans, *max_element(dp[u].begin(), dp[u].end()));
    cout << ans << "\n";
}

int main(){
    map<string, int> mp;
    auto get_id = [&](string s){
        if(!mp.count(s)){
            mp.emplace(s, sz(mp));
            flow.resize(sz(mp));
            g.resize(sz(mp));
        }
        return mp[s];
    };
    string line;
    while(getline(cin, line)){
        string s, from, to;
        char c;
        int fl;
        stringstream ss(line);
        ss >> s >> from >> s >> s >> c >> c >> c >> c >> c >> fl >> c >> s >> s >> s >> s;
        int fid = get_id(from);
        flow[fid] = fl;
        while(ss >> to){
            if(sz(to) == 3) to.pop_back();
            int tid = get_id(to);
            g[fid].push_back(tid);
        }
    }
    
    n = sz(g); k = 0;
    vector<pair<int, int>> byFlow;
    for(int i = 0; i < n; i++) byFlow.emplace_back(flow[i], i), k += (flow[i]>0);
    sort(byFlow.rbegin(), byFlow.rend());
    vector<int> p(n);
    for(int i = 0; i < n; i++) p[byFlow[i].second] = i;
    sort(flow.rbegin(), flow.rend());
    vector<vector<int>> g2(n);
    for(int i = 0; i < n; i++){
        for(int j : g[i]) g2[p[i]].push_back(p[j]);
    }
    g = g2;
    start = p[mp["AA"]];
    solve();
}