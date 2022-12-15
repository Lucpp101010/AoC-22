#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll big = 0, mid = 0, small = 0;
    ll val = 0;
    string line;
    auto empty = [&](){
        if(val > big){
            small = mid;
            mid = big;
            big = val;
        }
        else if(val > mid){
            small = mid;
            mid = val;
        }
        else if(val > small){
            small = val;
        }
        val = 0;
    };
    while(getline(cin, line)){
        if(line[0] < '0' || line[0] > '9'){
            empty();
        }
        else{
            val += stol(line);
        }
    }
    empty();
    cout << big+mid+small << "\n";
}