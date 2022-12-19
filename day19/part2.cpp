#include <bits/stdc++.h>
using namespace std;
constexpr int TIME = 32;
constexpr int ORE_HEURISTIC = 60, CLAY_HEURISTIC = 100, OBS_HEURISTIC = 40;
constexpr int ORE_MA_HEURISTIC = 4, CLAY_MA_HEURISTIC = 20, OBS_MA_HEURISTIC = 8;
int dp1[ORE_HEURISTIC+1][CLAY_HEURISTIC+1][OBS_HEURISTIC+1][ORE_MA_HEURISTIC+1][CLAY_MA_HEURISTIC+1][OBS_MA_HEURISTIC+1];
int dp2[ORE_HEURISTIC+1][CLAY_HEURISTIC+1][OBS_HEURISTIC+1][ORE_MA_HEURISTIC+1][CLAY_MA_HEURISTIC+1][OBS_MA_HEURISTIC+1];

typedef tuple<int, int, int, int, int, int> State;

int id, ore_ore, clay_ore, obs_ore, obs_clay, geo_ore, geo_obs;

int main(){
    int ans = 1;
    while(EOF != scanf("Blueprint %d: Each ore robot costs %d ore. Each clay robot costs %d ore. Each obsidian robot costs %d ore and %d clay. Each geode robot costs %d ore and %d obsidian.\n", &id, &ore_ore, &clay_ore, &obs_ore, &obs_clay, &geo_ore, &geo_obs)){
        if(id == 4) break;
        int best = 0;

        memset((int*)dp1, -1, sizeof(dp1) / 4);
        dp1[0][0][0][1][0][0] = 0;
        vector<State> states = {make_tuple(0, 0, 0, 1, 0, 0)};

        for(int t = 0; t < TIME-1; t++){
            memset((int*)dp2, -1, sizeof(dp2) / 4);
            vector<State> states2;
            auto vis = [&](int ore, int clay, int obs, int ma_ore, int ma_clay, int ma_obs, int val){
                ore = min(ore, ORE_HEURISTIC), clay = min(clay, CLAY_HEURISTIC), obs = min(obs, OBS_HEURISTIC);
                ma_ore = min(ma_ore, ORE_MA_HEURISTIC), ma_clay = min(ma_clay, CLAY_MA_HEURISTIC);
                ma_obs = min(ma_obs, OBS_MA_HEURISTIC);
                int& mem = dp2[ore][clay][obs][ma_ore][ma_clay][ma_obs];
                if(mem == -1) states2.emplace_back(make_tuple(ore, clay, obs, ma_ore, ma_clay, ma_obs));
                mem = max(mem, val);
                best = max(best, val);
            };

            for(auto [ore, clay, obs, ma_ore, ma_clay, ma_obs] : states){
                int val = dp1[ore][clay][obs][ma_ore][ma_clay][ma_obs];
                int nore = ore+ma_ore, nclay = clay+ma_clay, nobs = obs+ma_obs;
                vis(nore, nclay, nobs, ma_ore, ma_clay, ma_obs, val);
                if(ore >= ore_ore){
                    vis(nore-ore_ore, nclay, nobs, ma_ore+1, ma_clay, ma_obs, val);
                }
                if(ore >= clay_ore){
                    vis(nore-clay_ore, nclay, nobs, ma_ore, ma_clay+1, ma_obs, val);
                }
                if(ore >= obs_ore && clay >= obs_clay){
                    vis(nore-obs_ore, nclay-obs_clay, nobs, ma_ore, ma_clay, ma_obs+1, val);
                }
                if(ore >= geo_ore && obs >= geo_obs){
                    vis(nore-geo_ore, nclay, nobs-geo_obs, ma_ore, ma_clay, ma_obs, val+TIME-1-t);
                }
            }
            states = states2;
            swap(dp1, dp2);
        }
        ans *= best;
    }
    cout << ans << "\n";
}