#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
int main() {
    while(true) {
        ll n, m;
        cin >> n >> m;
        if(n==-1) break;
        ll maxi = 0;
        // vector<ll> pop(n);
        priority_queue<pair<ll, pair<ll, ll>>> pop;
        for(ll i=0; i<n; ++i) {
            ll popu;
            cin >> popu;
            pop.push({popu, {1, popu}});
        }
        // sort(pop.begin(), pop.end());
        ll j = m-n;
        ll ans = maxi;
        while (j>0) {
            pair<ll, pair<ll, ll>> el = pop.top();
            pop.pop();
            el.second.first++;
            el.first = el.second.second%el.second.first==0 ? el.second.second/el.second.first: el.second.second/el.second.first+1;
            // el.first = el.first%el.second==0 ? el.first*(el.second-1)/el.second: el.first*(el.second-1)/el.second+1;
            pop.push(el);
            --j;
        }
        cout << pop.top().first << endl;

    }
    return 0;
}