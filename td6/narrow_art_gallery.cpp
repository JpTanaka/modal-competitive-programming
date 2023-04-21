#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll rec(vector<pair<ll, ll>> const &vec, ll k, ll casa, ll index, ll total, vector<vector<vector<ll>>> &dp)
{
    if (vec.size() - index < k)
        return 0;
    if (k == 0)
        return total;
    // if (dp[k][index][casa] != 0)
    // {
    //     cout << dp[k][index][casa] << endl;
    //     return dp[k][index][casa];
    // }
    // for(ll i = 1; i<4; i++) {
    //     dp[k][index][i] = max(max(
    //                              (i != 2) ? rec(vec, k - 1, 1, index + 1, total - vec[index].first, dp) : 0,
    //                              (i != 1) ? rec(vec, k - 1, 2, index + 1, total - vec[index].second, dp) : 0),
    //                          rec(vec, k, 3, index + 1, total, dp));
    // }
    // return dp[k][index][casa];
    // return dp[k][index][casa] = max(max(
    //                              (casa != 2) ? rec(vec, k - 1, 1, index + 1, total - vec[index].first, dp) : 0,
    //                              (casa != 1) ? rec(vec, k - 1, 2, index + 1, total - vec[index].second, dp) : 0),
    //                          rec(vec, k, 3, index + 1, total, dp));
    if (casa == 1)
    {
        dp[k][index][casa] = max(rec(vec, k - 1, 1, index + 1, total - vec[index].first, dp), rec(vec, k, 3, index + 1, total, dp));
    }
    if (casa == 2)
    {
        dp[k][index][casa] = max(rec(vec, k - 1, 2, index + 1, total - vec[index].second, dp), rec(vec, k, 3, index + 1, total, dp));
    }
    if (casa == 3)
    {
        dp[k][index][casa] = max(max(
                                     rec(vec, k - 1, 1, index + 1, total - vec[index].first, dp),
                                     rec(vec, k - 1, 2, index + 1, total - vec[index].second, dp)),
                                 rec(vec, k, 3, index + 1, total, dp));
    }
    return dp[k][index][casa];
}

int main()
{
    while (true)
    {
        ll N, k;
        cin >> N >> k;
        if (N == 0 && k == 0)
            break;
        vector<pair<ll, ll>> vec(N);
        vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(N, vector<ll>(4)));
        ll total = 0;
        for (ll i = 0; i < N; i++)
        {
            cin >> vec[i].first >> vec[i].second;
            total += vec[i].first + vec[i].second;
        }
        for(ll i = 1; i<N; i++) {
            
        }
        cout << rec(vec, k, 3, 0, total, dp) << endl;
        // for (ll i = 0; i < N; i++)
        // {
        //     for (ll j = 0; j < N; j++)
        //     {
        //         cout << i << " " << j << " " <<    dp[i][j][1] << " " << dp[i][j][2] << " " << dp[i][j][3] << endl;
        //     }
        // }
    }

    return 0;
}