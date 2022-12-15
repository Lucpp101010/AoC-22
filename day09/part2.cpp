#include <bits/stdc++.h>
using namespace std;

constexpr int len = 10;

map<char, int> dx = {{'L', -1}, {'R', 1}, {'D', 0}, {'U', 0}};
map<char, int> dy = {{'L', -0}, {'R', 0}, {'D', -1}, {'U', 1}};

int sign(int x){
    if(x < 0) return -1;
    return min(1, x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    set<pair<int, int>> s;
    vector<pair<int, int>> rope(len);
    char dir;
    while(cin >> dir){
        int dist;
        cin >> dist;
        for(int i = 0; i < dist; i++){
            rope[0].first += dx[dir];
            rope[0].second += dy[dir];
            for(int j = 1; j < len; j++){
                auto a = rope[j-1], b = rope[j];
                if(max(abs(a.first-b.first), abs(a.second-b.second)) > 1){
                    rope[j].first += sign(a.first-b.first);
                    rope[j].second += sign(a.second-b.second);
                }
            }
            s.insert(rope[len-1]);
        }
    }
    cout << (int)s.size() << "\n";
}