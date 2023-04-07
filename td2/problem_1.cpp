#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    unordered_map<string, vector<int>> mp;
    cin >> n;
    for(int i=0; i<n; ++i) {
        string key;
        int a;
        cin >> key >> a;
        if (mp.find(key)!=mp.end()) mp[key].push_back(a);
        else {
            vector<int> v = {a};
            mp[key] = v;
        }
    }
    for(auto it=mp.begin(); it!=mp.end(); ++it) {
        sort((*it).second.begin(), it->second.end());
    }
    cin >> q;
    for(int i=0; i<q; ++i) {
        string key;
        int a;
        cin >> key >> a;
        cout << mp[key][a-1] << endl;
    }
    return 0;
}