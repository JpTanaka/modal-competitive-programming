#include <bits/stdc++.h>

// from icpc-notebook
// Trie <O(|S|), O(|S|)>
int trie[500000][26], trien = 1;

typedef long long ll;
using namespace std;

unordered_map<int, pair<ll, ll>> mp_trie;
// to add a string s in the trie
int add(int u, char c)
{
    c -= 'a';
    if (trie[u][c])
        return trie[u][c];
    trien++;
    trie[u][c] = trien;
    mp_trie[trien] = {u, c};
    return trien;
}
int main()
{
    while (true)
    {
        // create trie
        unordered_map<ll, string> mp_words;
        while (true)
        {
            string s;
            cin >> s;
            if (s == "#")
                break;
            int u = 1;
            for (char c : s)
                u = add(u, c);
            mp_words[u] = s;
        }
        while (true)
        {
            ll ans = 0;
            ll i = 1;
            ll l = 0;
            vector<ll> v;
            vector<ll> removed;
            while (true)
            {
                char c;
                cin >> c;
                if (c == '#')
                    return 0;
                if (c == '|')
                    break;
                v.push_back(1);

                for (ll j = l; j <= i; j++)
                {
                    if(find(removed.begin(), removed.end(), j)==removed.end()) continue;
                    // v[j] is the position of the j, we can treat it as u
                    if (trie[v[j]][c-'a'])
                    {
                        v[j] = trie[v[j]][c-'a'];
                        if (mp_words.find(v[j]) != mp_words.end())
                        {
                            ans++;
                            v.clear();
                            removed.clear();
                            l = 0;
                            break;
                        }
                    }
                    else removed.push_back(j);
                    
                }
                i++;
            }
            std::cout << ans << endl;
        }
    }

    return 0;
}