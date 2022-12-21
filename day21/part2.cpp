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

ll humn(string name, ll x){
    if(name == "humn") return x;
    if(!nodes.count(name)) return -1;
    Node u = nodes[name];
    ll l = val[u.le], r = val[u.ri];
    if(u.op == '+') return max(humn(u.le, x-r), humn(u.ri, x-l));
    if(u.op == '-') return max(humn(u.le, x+r), humn(u.ri, l-x));
    if(u.op == '*') return max(humn(u.le, x/r), humn(u.ri, x/l));
    return max(humn(u.le, x*r), humn(u.ri, l/x));
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
    calc("root");
    Node r = nodes["root"];
    ll me = max(humn(r.le, val[r.ri]), humn(r.ri, val[r.le]));
    cout << me << "\n";
}