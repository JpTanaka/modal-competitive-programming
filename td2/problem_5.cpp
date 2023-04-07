#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
int main() {
    string str;
    cin >> str;
    ll count = 0;
    ll counti = 0;
    ll powi = 1;
    ll ans = 0;
    for (int i=0; i<str.length(); i++) {
        if (str[i]=='1') {
            count++;
        }
        if(str[i]=='0') {
            ans+= count * powi;
            ans += (counti == 0) ? 0 : counti * ((500000004 * powi) % 1000000007);

        }
        if (str[i]=='?') {
            ans*=2;
            ans+= count * powi;
            ans += (counti == 0) ? 0 : counti * ((500000004 * powi) % 1000000007);
            
            counti+=1;
            powi = (powi * 2) % 1000000007;
        }
        ans = ans%1000000007;
        // cout << ans << endl;
    }
    cout << ans%1000000007;
    return 0;
}