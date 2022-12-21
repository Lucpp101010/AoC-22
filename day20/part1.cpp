#include <bits/stdc++.h>
using namespace std;


int sign(int x){
    if(x < 0) return -1;
    return x == 0 ? 0 : 1;
}

int main(){
    vector<int> a;
    int x;
    while(cin >> x) a.push_back(x);
    int n = (int)a.size();
    vector<bool> todo(n, true);
    for(int i = 0; i < n; i++){
        int j;
        for(j = 0; j < n && !todo[j]; j++);
        todo[j] = false;
        int p = (j+a[j])%(n-1);
        if(p <= 0) p += n-1;
        while(j != p){
            int k = j+sign(p-j);
            swap(a[j], a[k]);
            swap(todo[j], todo[k]);
            j = k;
        }
    }
    int z;
    for(z = 0; z < n && a[z] != 0; z++);
    int v1 = a[(z+1000)%n], v2 = a[(z+2000)%n], v3 = a[(z+3000)%n];
    cout << v1+v2+v3 << "\n";
}