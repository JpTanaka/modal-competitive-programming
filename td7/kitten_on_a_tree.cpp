#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
int main() {
    ll K;
    vector<vector<ll>> branchs;
    ll j = 0;
    while(true) {
        string line;
        getline(cin, line);
        istringstream ss(line);
        cout << line;
        if (line=="-1") break;
        branchs.push_back({});
        string word;
        while(ss>> word) {
            branchs[j].push_back(stoi(word));
        }
        j++;
    }
            cout << "fasdfasdf";
    unordered_map<ll, vector<ll>> mp;
    for(auto it = branchs.begin(); it!=branchs.end(); it++) {
        for(auto it2 = it->begin(); it2 != it->end(); it2++) {
            if(*it2 != (*it)[0]) mp[(*it)[0]].push_back(*it2);
        }
    }
    deque<ll> deq = {branchs[0][0]};
    ll counter = 0;
    bool find = false;
    vector<ll> ans;
    vector<bool> seen(101);
    unordered_map<ll, ll> backtrack;
    seen[deq.front()] = true;    
    while(!deq.empty()) {
        ll current = deq.front();
        deq.pop_front();
        for(ll neigh : mp[current]) {
            if(!seen[neigh]) {
                seen[neigh]=true;
                deq.push_back(neigh);
                backtrack[neigh] = current;
                if(neigh == branchs[1][0]) {
                    find = true;
                    ans.push_back(neigh);
                    break;
                }
            }
        }
        if(find)  break;
    }
    ll current = ans[0];
    while(current != branchs[0][0]) {
        current = backtrack[current];
        ans.push_back(current);
    }
    for(auto it = ans.begin(); it!=ans.end(); it++) {
        cout << (*it) << " ";
    }
    cout << counter;
    return 0;
}