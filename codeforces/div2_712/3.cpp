#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int t;cin>>t;while(t--) {
        int n; cin>>n;char c[10];cin.getline(c,10);char s[n+5];cin.getline(s,n+5);
        int cnt = 0;
        char a[n+5],b[n+5];memset(a,0,sizeof(a));memset(b,0,sizeof(b));
        if (s[0] != '1' || s[n-1] != '1') {
            cout<<"NO\n";continue;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') cnt++;
        }
        if (cnt%2) {
            cout<<"NO\n";continue;
        }
        int k = 0;
        bool flip = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (2*k<cnt) {
                    a[i] = b[i] = '(';
                }
                else {
                    a[i] = b[i] = ')';
                }
                k++;
            } else {
                if (!flip) {
                    a[i] = ')';b[i] = '(';
                }
                else { 
                    a[i] = '(';b[i] = ')';
                }
                flip = !flip;
            }
        }
        cout<<"YES\n"<<a<<"\n"<<b<<"\n";
    }
    return 0;
}