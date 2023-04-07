#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> times(n);
    for(ll i=0; i<n; ++i) {
        ll s, f;
        cin >> s >> f;
        times[i] = {f, s};
    }
    sort(times.begin(), times.end());
    multiset<ll, greater<ll>> rooms;
    ll a = 0;
    ll ans = 0;
    for(ll i=0; i<m; i++) {
        rooms.insert(0);
    }
    for(ll i=0; i<n; i++) {
        // temos um times com os menores tempos de final na frente
        auto good_room = rooms.upper_bound(times[i].second);
        if(good_room != rooms.end()) {
            // --good_room;
            rooms.erase(good_room);
            rooms.insert(times[i].first);
            ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}