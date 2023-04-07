#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> tasks;
    for(ll i=0; i<n; ++i) {
        ll task;
        cin >> task;
        tasks.push_back(task);
    }
    vector<ll> times;
    for(ll i=0; i<m; ++i) {
        ll time;
        cin >> time;
        times.push_back(time);
    }

    sort(times.begin(), times.end());
    sort(tasks.begin(), tasks.end());
    ll j = times.size()-1;
    ll ans = 0;
    for(ll i=tasks.size()-1; i>=0; --i) {
        if (tasks[i]>times[j]) continue;
        ans++;
        --j;
        if (j==-1) break;
    }
    cout << ans;
    return 0;
}