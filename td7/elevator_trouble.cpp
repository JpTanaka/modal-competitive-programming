#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
int main() {
    ll f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    deque<ll> deq = {s};
    unordered_map<ll, bool> taken;
    taken[s] = true;
    ll level = 0;
    ll count_childs = 1;
    ll cumulative_childs = 0;
    bool find = false;

    if(s == g) {
        cout << 0;
        return 0;
    }
    while(!deq.empty()) {
        ll current = deq.front();
        deq.pop_front();
        ll down = current-d;
        ll up = current+u;
        
        if(down == g || up == g) {
            cout << level + 1 << endl;
            find = true;
            break;
        }
        if(!taken[down] && down>=1) {
            deq.push_back(down);
            taken[down] = true;
            cumulative_childs++;
        }
        if(!taken[up] && up<=f) {
            deq.push_back(up);
            taken[up] = true;
            cumulative_childs++;
        }
        count_childs--;
        if(count_childs == 0){
            level++;
            count_childs = cumulative_childs;
            cumulative_childs = 0;
        } 
    }
    if(!find) cout << "use the stairs";
    return 0;
}