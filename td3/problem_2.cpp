#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
using namespace std;
struct quad {
    ll x;
    ll y;
    ll w;
    ll h;
    ll area;
};

bool colision(ll q, vector<quad> &quads, vector<bool> &used) {
    quad a = quads[q];
    for(int j=0; j<used.size(); j++) {
            if (used[j]!=1 || j==q) continue;
            quad b = quads[j];
            if(a.x+a.w==b.x || a.y+a.h==b.y || a.x==b.x+b.w || a.y==b.y+b.h) continue;
            if (((a.x<=b.x && b.x<=a.x+a.w) || 
            (a.x<=b.x + b.w && b.x + b.w<=a.x+a.w))  && 
            ((a.y <= b.y && b.y <= a.y+a.h) ||
            (a.y<=b.y + b.h && b.y + b.h <=a.y+a.h))) {
                return 1;
            }
            quad c = b;
            b = a;
            a = c;
            if (((a.x<=b.x && b.x<=a.x+a.w) || 
            (a.x<=b.x + b.w && b.x + b.w<=a.x+a.w))  && 
            ((a.y <= b.y && b.y <= a.y+a.h) ||
            (a.y<=b.y + b.h && b.y + b.h <=a.y+a.h))) {
                return 1;
            }
        }
    return 0;
}


ll rec(ll q, vector<quad> &quads, vector<bool> &used) {
    used[q] = 1;

    ll a = quads[q].area;
    for(ll i = 0; i<quads.size(); i++) {
        if(used[i]==1) continue;
        if(colision(i, quads, used)==0) {
            a = max(a, quads[q].area+
            rec(i, quads, used));
        }
        
    }
    // used[q] = 0;
    return a;
}

int main() {
    int n;
    while(cin >> n) {
        if (n==0) break;
        vector <quad> vec;
        for(ll i=0; i<n; i++) {
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            struct quad q;
            q.x = c;
            q.y = d;
            q.w = a;
            q.h = b;
            q.area = a*b;
            vec.push_back(q);
        }
        ll maxi = 0;
        for(ll i=0; i<vec.size(); i++ ) {
            vector<bool> used(n);
            ll m=0;
            m = rec(i, vec, used);
            maxi = max(maxi, m);
            // for(auto it=used.begin(); it!=used.end(); it++) {
            //     cout << *it << " ";
            // }
        }
        cout << maxi << endl;
    }
    return 0;
}