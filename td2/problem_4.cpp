#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ll n, t, m;
    cin >> t;
    for (ll i=0; i<t; i++) {
        cin >> n;
        ll cum_task = 0;
        unordered_map<ll, ll> mp;
        for(ll j=0; j<n; j++) {
            cin >> m;
            ll cum = 0;
            for(ll k=0; k<m-1; k++) {
                ll memory;
                cin >> memory;
                cum = max(cum, mp[memory]);
            }
            ll write;
            cin >> write;
            mp[write]=cum+1;
            cum_task=max(mp[write], cum_task);
        }
        cout << i+1 << " " << cum_task << endl;
    }
    return 0;
}