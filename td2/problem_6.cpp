#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ll n;
    while (true) {
        cin >> n;
        if (n==0) break;
        char b;
        cin>>b;
        vector<ll> v;
        for (ll i = 0; i<n; i++) {
            ll c;
            cin >> c;
            v.push_back(c);
        }
        bool bol = false;
        for (ll i=0;i<v.size(); i++) {
            // unordered_set<ll> s;
            vector<bool> vis(2*n+1);
            for (ll j=i; j < v.size();j++) {
                if ((v[j]-v[i])%2==0 && vis[(v[j]-v[i])/2+n]) {
                    cout << "no" << endl;
                    bol = true;
                    break;
                }
                // s.insert(v[j]-v[i]);
                vis[v[j]-v[i] + n] = true;
            }
            if(bol) break;
        }
        if(!bol) cout<<"yes" << endl;
    }
    return 0;
}