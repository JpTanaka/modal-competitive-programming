#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> weights(n);
    for(ll i=0; i<n; ++i) {
        ll weight;
        cin >> weight;
        weights[i] = weight;
    }
    vector<pair<ll, ll>> mong(m);
    for(ll i=0; i<m; ++i) {
        ll fish, price;
        cin >> fish >> price;
        mong[i] = make_pair(price, fish);
    }

    sort(weights.begin(), weights.end());
    sort(mong.begin(), mong.end());
    ll j = weights.size()-1;
    ll ans = 0;
    for(ll i=mong.size()-1; i>=0; --i) {
        // cout << mong[i].first << " " << mong[i].second << endl;
        for(ll k=0; k<mong[i].second; k++) {
            ans+=mong[i].first*weights[j];
            j--;
            if (j<0) break;
        }
        if (j<0) break;
    }
    cout << ans;
    return 0;
}