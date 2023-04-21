#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ll w, n, total_vol;
    cin >> w;
    cin >> n;
    total_vol = 0;
    for(ll i=0; i<n; i++) {
        ll a, b;    
        cin >> a >> b;
        total_vol+=a*b;
    }
    cout << total_vol/w;
    return 0;
}
