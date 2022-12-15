#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Y = 2000000;

int main(){
    set<pair<int, int>> beacons;
    vector<pair<int, int>> v;
    int x1, y1, x2, y2, ans = 0;
    while(EOF != scanf("Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d\n", &x1, &y1, &x2, &y2)){
        int d = abs(x1-x2)+abs(y1-y2);
        int dy = abs(y1-Y);
        if(dy <= d){
            int l = x1-(d-dy), r = x1+(d-dy);
            v.emplace_back(l, r);
        }
        if(y2 == Y && !beacons.count(make_pair(x2, y2))) ans--;
        beacons.emplace(x2, y2);
    }
    // Standard-problem: Find the size of the union of intervals in O(n * log(n))
    sort(v.begin(), v.end());
    int ma = -1e9;
    for(auto [l, r] : v){
        if(l <= ma) ans += max(0, r-ma);
        else ans += r-l+1;
        ma = max(ma, r);
    }
    cout << ans << "\n";
}