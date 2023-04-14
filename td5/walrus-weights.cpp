#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin >> n;
    vector<ll> vec;
    ll a;
    for(ll i=0; i<n; i++) {
        cin >> a;
        vec.push_back(a);
    }
    vector<bool> weights(2001);
    weights[0] = true;
    for(ll i=0; i<n; i++) {
        vector<bool> seen(2001);
        for(ll j=0; j<2001-vec[i]; j++) {
            if(!seen[j] && weights[j]) {
                seen[j+vec[i]]=!weights[j+vec[i]];
                weights[j+vec[i]]=true;
            }
        }
    }
    ll i = 0;
    while(i<=1000) {
        if(weights[1000+i]) {
            cout << 1000+i;
            break;
        }
        if(weights[1000-i]) {
            cout << 1000-i;
            break;
        }
        i++;
    }
    return 0;
}
