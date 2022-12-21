#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    string le, ri;
    char op;
};

map<string, ll> val;
map<string, Node> nodes;

ll calc(string name){
    if(val.count(name)) return val[name];
    Node u = nodes[name];
    ll le = calc(u.le), ri = calc(u.ri);
    ll ans;
    if(u.op == '+') ans = le+ri;
    else if(u.op == '-') ans = le-ri;
    else if(u.op == '*') ans = le*ri;
    else{
        assert(le % ri == 0);
        ans = le/ri;
    }
    return val[name] = ans;
}

int main(){
    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        string name, le, op, ri;
        if(ss >> name >> le >> op >> ri){
            name.pop_back();
            nodes[name] = Node{le, ri, op[0]};
        }
        else{
            name.pop_back();
            val[name] = stoi(le);
        }
    }
    cout << calc("root") << "\n";
}