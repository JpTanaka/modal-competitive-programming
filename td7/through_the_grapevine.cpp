#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
int main() {
    ll n, m, d;
    cin >> n >> m >> d;
    unordered_map<string, ll> names;
    vector<vector<ll>> relations(n);
    vector<ll> skept(n);

    for(ll i = 0; i<n; i++) {
        string s;
        ll t;
        cin >> s >> t;
        skept[i] = t;
        names[s] = i;        
    }
    for(ll i = 0; i<m; i++) {
        string s, t;
        cin >> s >> t;
        relations[names[s]].push_back(names[t]);
        relations[names[t]].push_back(names[s]);
    }

    string first;
    cin >> first;
    deque<ll> deq = {names[first]};
    ll counter = 0;
    vector<bool> heard(n);
    heard[names[first]] = true;    
    ll count_childs = 1;
    ll cumulative_childs = 0;
    while(!deq.empty() && d>0) {
        ll current = deq.front();
        deq.pop_front();

        for(ll neigh : relations[current]) {
            skept[neigh]--;
            if(!heard[neigh]) {
                counter++;
                heard[neigh]=true;
            }
            if(skept[neigh]==0){
                cumulative_childs++;
                deq.push_back(neigh);
            }
        }
        count_childs--;
        if(count_childs == 0){
            d--;
            count_childs = cumulative_childs;
            cumulative_childs = 0;
        } 
    }
    cout << counter;
    return 0;
}