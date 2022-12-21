#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sign(ll x){
    if(x < 0) return -1;
    return x == 0 ? 0 : 1;
}

int main(){
    vector<pair<ll, int>> a;
    ll x; int id = 0;
    while(cin >> x) a.emplace_back(x * 811589153, id++);
    ll n = (ll)a.size();
    for(int t = 0; t < 10; t++){
        for(int i = 0; i < n; i++){
            int j;
            for(j = 0; j < n && a[j].second != i; j++);
            ll p = (j+a[j].first)%(n-1);
            if(p <= 0) p += n-1;
            while(j != p){
                int k = j+sign(p-j);
                swap(a[j], a[k]);
                j = k;
            }
        }
    }
    int z;
    for(z = 0; z < n && a[z].first != 0; z++);
    ll v1 = a[(z+1000)%n].first, v2 = a[(z+2000)%n].first, v3 = a[(z+3000)%n].first;
    cout << v1+v2+v3 << "\n";
}