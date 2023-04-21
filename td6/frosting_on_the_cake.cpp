#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin >> n;
    vector<ll> A(3);
    vector<ll> B(n);
    vector<ll> colors(3);
    ll cum_sum = 0;
    for(ll i=0; i<n; i++) {
        ll a;
        cin >> a;
        A[(i+1)%3] += a;
    }
    for(ll i=0; i<n; i++) {  
        cin >> B[i];
        colors[(i+1)%3] += B[i]*A[0];
        colors[(i+2)%3] += B[i]*A[1];
        colors[(i+3)%3] += B[i]*A[2];
    }
    // for(ll i=0; i<n; i++) {  
    //     for(ll j=0; j<n; j++) {
    //         colors[((j+1)+(i+1))%3] += A[i]*B[j];
    //     }
    // }
    cout << colors[0] << " " << colors[1] << " " << colors[2];
    return 0;
}
