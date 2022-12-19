#include <bits/stdc++.h>
using namespace std;
constexpr int TIME = 24;
typedef tuple<int, int, int, int, int, int, int> State;
map<State, int> memo;

int id, ore_ore, clay_ore, obs_ore, obs_clay, geo_ore, geo_obs;

int solve(int t, int ore, int clay, int obs, int ma_ore, int ma_clay, int ma_obs){
    if(t == TIME-1) return 0;
    State st = make_tuple(t, ore, clay, obs, ma_ore, ma_clay, ma_obs);
    if(memo.count(st)) return memo[st];

    int nore = ore+ma_ore, nclay = clay+ma_clay, nobs = obs+ma_obs;
    int ans = solve(t+1, nore, nclay, nobs, ma_ore, ma_clay, ma_obs);
    if(ore >= ore_ore){
        ans = max(ans, solve(t+1, nore-ore_ore, nclay, nobs, ma_ore+1, ma_clay, ma_obs));
    }
    if(ore >= clay_ore){
        ans = max(ans, solve(t+1, nore-clay_ore, nclay, nobs, ma_ore, ma_clay+1, ma_obs));
    }
    if(ore >= obs_ore && clay >= obs_clay){
        ans = max(ans, solve(t+1, nore-obs_ore, nclay-obs_clay, nobs, ma_ore, ma_clay, ma_obs+1));
    }
    if(ore >= geo_ore && obs >= geo_obs){
        ans = max(ans, TIME-1-t + solve(t+1, nore-geo_ore, nclay, nobs-geo_obs, ma_ore, ma_clay, ma_obs));
    }
    return memo[st] = ans;
}

int main(){
    int ans = 0;
    while(EOF != scanf("Blueprint %d: Each ore robot costs %d ore. Each clay robot costs %d ore. Each obsidian robot costs %d ore and %d clay. Each geode robot costs %d ore and %d obsidian.\n", &id, &ore_ore, &clay_ore, &obs_ore, &obs_clay, &geo_ore, &geo_obs)){
        int best = solve(0, 0, 0, 0, 1, 0, 0);
        memo.clear();
        ans += id*best;
    }
    cout << ans << "\n";
}