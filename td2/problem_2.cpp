#include<bits/stdc++.h>
using namespace std;

bool check_prime(long long n) {
    float arret = sqrt(n);
    if (n==2) return true;
    for(long long i=2; i<arret+1; i++) {
        if (n%i==0) return false;
    }
    return true;
}

int main() {
    long long n;
    while(cin>>n) {
        if (n==0) break;
        bool check = check_prime(n);
        long long a = n*2;
        while (true) {
            ++a;
            if(check_prime(a)) {
                cout << a;
                if (!check) cout << " (" << n << " is not prime)" << endl;
                else cout <<endl;
                break;
            }
        }

    }
    return 0;
}