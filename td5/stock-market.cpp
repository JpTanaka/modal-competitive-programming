#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dd;
int main() {
    ll n;
    cin >> n;
    dd q;
    cin >> q;
    vector<dd> price(n);
    dd a;
    for(ll i=0; i<n; i++) {
        cin >> a;
        price[i] = a;
    }
    vector<dd> answer(n, 100);
    a = 100;
    dd b = 0;
    ll left = 0;
    ll right = 0;
    dd maxi = price[0];
    for(ll i=0; i<n; i++) {
        dd c = a;
        a = max(a, b*price[i]-q);
        b = max(b, (c-q)/price[i]);
        // // answer[i] = max(answer[i], ((answer[i-1]-q)/price[i-1])*price[i]-q);
        // for(ll j=0; j<=i; j++) {
        //     answer[i] = max(answer[i], 
        //     max(answer[j],
        //     ((answer[j]-q)/price[j])*price[i]-q));
        // }

    }
    cout << setprecision(6) << max(a, b);
    return 0;
}
