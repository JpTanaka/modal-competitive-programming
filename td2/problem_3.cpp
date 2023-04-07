#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
bool cmp(pair<string, int> &a, pair<string, int> &b) {
    return a.second==b.second ? a.first<b.first : a.second<b.second;
}
int main() {
    long long m;
    cin >> m;
    unordered_set<string> answer;
    set<pair<int, string>> freq;
    unordered_map<string, int> words;
    unordered_map<string, unordered_set<string>> mp;
    for(ll i=0; i<m; ++i) {
        string name, text;
        cin >> name;
        getline(cin, text);
        stringstream ss(text);
        string word;
        while (ss>>word) {
            words[word]++;
            mp[name].insert(word);
        }
    }
    for (auto it =words.begin(); it!=words.end(); it++) {
        bool put = true;
        for (auto it2 = mp.begin(); it2!=mp.end(); it2++) {
            if (it2->second.find(it->first)==it2->second.end()) {
                put = false;
                break;
            }
        }
        if (put) answer.insert(it->first);
    }
    for(auto it = answer.begin(); it!=answer.end();++it) {
        pair<int, string> p = {-words[*it], *it};
        freq.insert(p);
    }

    if (freq.empty()) {
        cout << "ALL CLEAR" << endl;
        return 0;
    }
    // // sort(words.begin(), words.end(), cmp);
    for(auto it=freq.begin(); it!=freq.end();++it) {
        cout << it->second << endl; 
    }


    return 0;
}