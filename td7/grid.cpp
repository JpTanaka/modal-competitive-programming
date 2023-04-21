#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> table(n, vector<ll>(m));
    for(ll i = 0; i<n; i++) {
        string s;
        cin >> s;
        for(ll j = 0; j<m; j++) {
            table[i][j] = (ll)s[j]-'0';
        }
    }
    deque<pair<ll, ll>> deq = {{0,0}};
    vector<vector<bool>> taken(n, vector<bool>(m, false));
    taken[0][0] = true;
    ll level = 0;
    ll count_childs = 1;
    ll cumulative_childs = 0;
    bool find = false;

    while(!deq.empty()) {
        pair<ll, ll> current = deq.front();
        deq.pop_front();
        ll quantity = table[current.first][current.second];
        vector<pair<ll,ll>> moves;
        pair<ll, ll> down = {current.first+quantity, current.second};
        pair<ll, ll> up = {current.first-quantity, current.second};
        pair<ll, ll> left = {current.first, current.second-quantity};
        pair<ll, ll> right = {current.first, current.second+quantity};
        moves.push_back(down);
        moves.push_back(up);
        moves.push_back(right);
        moves.push_back(left);
        for(auto it : moves) {
            if(it.first == n-1 && it.second == m-1){
                cout << level + 1 << endl;
                find = true;
                break;
            }

            if(it.first >=0 && it.first<n && it.second >=0 && it.second<m && !taken[it.first][it.second]) {
                deq.push_back(it);
                taken[it.first][it.second] = true;
                cumulative_childs++;
            }
        }
        if(find) break;
        count_childs--;
        if(count_childs == 0){
            level++;
            count_childs = cumulative_childs;
            cumulative_childs = 0;
        } 
    }
if(!find) cout << "-1";

    return 0;
}