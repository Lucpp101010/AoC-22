#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Monkey{
    char op;
    int val;
    int test;
    int tr, fa;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string line;
    vector<Monkey> monkeys;
    vector<queue<int>> items;
    vector<int> cnt;
    while(getline(cin, line)){
        items.push_back(queue<int>());
        cnt.push_back(0);
        Monkey mon;
        // items
        getline(cin, line);
        stringstream ss(line);
        string useless;
        ss >> useless;
        int x;
        while(ss >> useless){
            ss >> x;
            items.back().push(x);
        }
        // operation
        getline(cin, line);
        ss = stringstream(line);
        string strVal;
        ss >> useless >> useless >> useless >> useless >> mon.op >> strVal;
        if(strVal != "old") mon.val = stoi(strVal);
        else mon.op = '^';
        // test value
        getline(cin, line);
        ss = stringstream(line);
        ss >> useless >> useless >> useless >> mon.test;
        // test result
        getline(cin, line);
        ss = stringstream(line);
        ss >> useless >> useless >> useless >> useless >> useless >> mon.tr;
        getline(cin, line);
        ss = stringstream(line);
        ss >> useless >> useless >> useless >> useless >> useless >> mon.fa;
        monkeys.push_back(mon);
        getline(cin, line);
    }

    for(int round = 0; round < 20; round++){
        for(int i = 0; i < (int)monkeys.size(); i++){
            while(!items[i].empty()){
                int x = items[i].front();
                items[i].pop();
                cnt[i]++;
                if(monkeys[i].op == '^') x *= x;
                else if(monkeys[i].op == '+') x += monkeys[i].val;
                else x *= monkeys[i].val;
                x = x/3;
                if(x % monkeys[i].test == 0) items[monkeys[i].tr].push(x);
                else items[monkeys[i].fa].push(x);
            }
        }
    }

    sort(cnt.rbegin(), cnt.rend());
    cout << cnt[0]*cnt[1] << "\n";
}