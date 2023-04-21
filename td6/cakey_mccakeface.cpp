#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ll n, m;
    cin >> n;
    cin >> m;
    vector<ll> in(n);
    vector<ll> out(m);
    unordered_map<ll, ll> guesses;
    for(ll i=0; i<n; i++) {  
        cin >> in[i];
    }
    for(ll i=0; i<m; i++) {  
        cin >> out[i];
    }
    for(ll i=0; i<n; i++) {  
        for(ll j=0; j<m; j++) {  
            if(in[i]>out[j]) continue;
            guesses[out[j]-in[i]]++;
        }
    }
    ll mini = 0;
    ll mini2 = 0;
    for(auto it = guesses.begin(); it !=guesses.end();it++) {
        // cout << it->first << " " << it->second << endl;
        if(it->second == mini && mini2 > it->first) {
            mini2 = min(mini2, it->first);
            mini = it->second;
        }
        if(it->second > mini) {
            mini2 = it->first;
            mini = it->second;
        }
    }
    cout << mini2;
    return 0;
}
