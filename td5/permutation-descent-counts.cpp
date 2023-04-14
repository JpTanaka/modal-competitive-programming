#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dd;
ll quantity_permutations(ll N, ll v, vector<vector<ll>> &answers) {
    if( v==0) return 1;
    if(N == v+1) return 1;
    if(answers[N-1][v-1]==-1) answers[N-1][v-1] = quantity_permutations(N-1, v-1, answers);
    if(answers[N-1][v]==-1) answers[N-1][v] = quantity_permutations(N-1, v, answers);
    answers[N][v] = ((N-v)*answers[N-1][v-1] + (v+1)*answers[N-1][v]) % 1001113 ;
    return answers[N][v]; 
}


int main() {
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++) {
        ll a, N, v;
        cin >> a >> N >> v;
        vector<vector<ll>> answers(N+1, vector<ll>(v+1, -1));
        cout << a << " " << quantity_permutations(N, v, answers) % 1001113 << endl;
    }
    return 0;
}


