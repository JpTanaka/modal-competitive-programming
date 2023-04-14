#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dd;


int main() {
    ll n, w;
    cin >> n >> w;
    vector<vector<ll>> answers(27, vector<ll>(n));
    if(w<n || n*26<w) {
        cout << "impossible" << endl;
    }
    else {
        ll counter = w-n;
        ll letters = 0;
        string s;
        while(counter>25) {
            s +="z";
            counter -=25;
            letters++;
        }
        s+='a'+counter;
        letters++;
        while(letters<n) {
            s+= "a";
            letters++;
        }
        cout << s << endl;
    }
    return 0;
}
