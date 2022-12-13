#include <bits/stdc++.h>
using namespace std;

// -2 = [     -1 = ]
vector<int> parse(string s){
    vector<int> ans;
    string last;
    for(char c : s){
        if('0' <= c && c <= '9') last += c;
        else if(!last.empty()){
            ans.push_back(stoi(last));
            last.clear();
        }
        if(c == '[') ans.push_back(-2);
        else if(c == ']') ans.push_back(-1); 
    }
    reverse(ans.begin(), ans.end()); // Use pop_back for fast deletion
    return ans;
}

bool compare(vector<int> le, vector<int> ri){
    while(!le.empty()){
        if(le.back() == ri.back()){
            le.pop_back();
            ri.pop_back();
            continue;
        }
        if(le.back() != -1 && ri.back() == -1) return false;
        if(le.back() == -1 && ri.back() != -1) return true;
        if(le.back() == -2 && ri.back() >= 0){
            int temp = ri.back();
            ri.pop_back();
            ri.push_back(-1);
            ri.push_back(temp);
            ri.push_back(-2);
            continue;
        }
        if(le.back() >= 0 && ri.back() == -2){
            int temp = le.back();
            le.pop_back();
            le.push_back(-1);
            le.push_back(temp);
            le.push_back(-2);
            continue;  
        }
        return le.back() < ri.back();
    }
    assert(false);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string le, ri;
    vector<int> d1 = parse("[[2]]"), d2 = parse("[[6]]");
    vector<vector<int>> v = {d1, d2};
    while(getline(cin, le)){
        getline(cin, ri);
        v.push_back(parse(le));
        v.push_back(parse(ri));
        getline(cin, le);
    }
    sort(v.begin(), v.end(), compare);
    int p1 = 0, p2 = 0;
    for(int i = 0; i < (int)v.size(); i++){
        if(v[i] == d1) p1 = i+1;
        if(v[i] == d2) p2 = i+1;
    }
    cout << p1*p2 << "\n";
}