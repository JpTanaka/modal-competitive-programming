#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ll c, n;
    while(cin >> c >> n) {
        vector<ll> weights(n);
        vector<ll> values(n);
        for(ll i=0; i<n; i++) {
            cin >> values[i] >> weights[i];
        }
        vector<vector<ll>> matrix(n, vector<ll>(c+1));
        for(ll j = weights[0]; j<c+1; j++) {
            matrix[0][j] = values[0];
        }
        for(ll i=1; i<n; i++) {
            for(ll j=weights[i]; j<c+1; j++) {
                // if(j-weights[i] <0) continue;
                matrix[i][j] =max(matrix[i-1][j-weights[i]]+values[i], matrix[i-1][j]);
            }
        }
        for(auto it = matrix.begin() ; it != matrix.end(); it++) {
            for(auto it2 = it->begin(); it2!= it->end();it2++) {
                cout << *it2 << " ";
            }
            cout << endl;
        }
        vector<ll> answers;
        ll d = 0;
        ll i = n-1;
        ll j = c;
        while(i >=0 && matrix[i][j]!=0) {
            if(i==0) {
                if(j>=weights[i]) {
                    answers.push_back(i);
                    d++;
                    break;
                }
            }
            if(j-weights[i]>= 0 && matrix[i][j]!=0 && matrix[i][j] == matrix[i-1][j-weights[i]]+values[i]) {
                answers.push_back(i);
                d++;
                j = j-weights[i];
            }
            i--;
        }
        cout << d << endl;
        for(auto it=answers.begin(); it!= answers.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;

    }
    return 0;
}
