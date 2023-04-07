#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
using namespace std;

int f(ll color, vector<ll> &colors, vector<bool> &used, vector<vector<bool>> &adj, ll maxi, ll *ans, bool *a, ll counter,  vector<ll> vec, vector<ll> *v) {
    if (counter==maxi-1) {
        if (!(*a)) {
            for(auto it=vec.begin(); it!=vec.end(); it++) {
                v->push_back(*it);
            }
            v->push_back(color);
        }
        *a=true;
        (*ans)++;
        return 1;
    }
    // colors.erase(find(colors.begin(), colors.end(), color));
    used[color]=1;
    if (!(*a)) vec.push_back(color);
    counter++;
    for(auto it=colors.begin(); it!=colors.end(); it++) {
        if(adj[color][*it]==1 || used[*it]==1) continue;
        f(*it, colors, used, adj, maxi, ans, a, counter, vec, v);
    }
    used[color]=0;
    return 0;
}


int main() {
    ll T; cin >> T;
    for(ll i=0; i<T; i++) {
        ll n; cin >> n;
        vector<string> colors;
        vector<ll> colors_index;
        unordered_map<string, ll> mp_colors;
        unordered_map<ll, string> mp_index;
        for(ll j=0; j<n; j++) {
            string s;
            cin >> s;
            colors.push_back(s);
            colors_index.push_back(j);
            mp_colors[s] = j;
            mp_index[j] = s;
        }
        ll b; cin >> b;
        // unordered_map<ll, vector<ll>> adj;
        vector<vector<bool>> adj(n, vector<bool>(n, false));
        for(ll j=0; j<b; j++) {
            string a, c;
            cin >> a >> c;
            adj[mp_colors[a]][mp_colors[c]] = true;
            adj[mp_colors[c]][mp_colors[a]] = true;
        }
        ll ans = 0;
        bool a = false;
        vector<ll> vec;
        vector<ll> v;
        for(auto it=colors_index.begin(); it!=colors_index.end(); it++) {
            vector<bool> used(n);
            f(*it, colors_index, used, adj, n, &ans, &a, 0, vec, &v);
        }
        cout <<ans << endl;
        for(ll i=0; i!= v.size()-1; i++) {
            cout << mp_index[v[i]] << " ";
        }
        cout << mp_index[v[v.size()-1]] << endl;
    }    
    return 0;
}