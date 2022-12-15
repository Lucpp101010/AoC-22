#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 4000000;

int main(){
    vector<tuple<int, int, int>> a;
    int x1, y1, x2, y2;
    while(EOF != scanf("Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d\n", &x1, &y1, &x2, &y2)){
        int d = abs(x1-x2)+abs(y1-y2);
        a.emplace_back(x1, y1, d);
    }
    for(int Y = 0; Y <= MAX; Y++){
        vector<pair<int, int>> v;
        for(auto [x, y, d] : a){
            int dy = abs(y-Y);
            int l = max(0, x-(d-dy)), r = x+(d-dy);
            if(r >= l) v.emplace_back(l, r);
        }
        sort(v.begin(), v.end());
        int ma = 0;
        for(auto [l, r] : v){
            if(l > ma+1){
                ll x = l-1, y = Y;
                ll ans = x * 4000000 + y;
                cout << ans << "\n";
            }
            ma = max(ma, r);
        }
    }
}