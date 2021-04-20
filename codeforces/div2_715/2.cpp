#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[(int)1e5+5];
int main() {
    int t; cin>>t; while (t--) {
        int n; cin>>n; memset(s,0,sizeof(s));char c[10];cin.getline(c,10); cin.getline(s,n+1);
        bool flag = true; int theadcnt = 0; for (int i = 0; i < n; i++) { if (s[i] == 'T') theadcnt++; else { if (theadcnt <= 0) { flag = false; break;} else theadcnt--;}}
        if (!flag) {cout<<"NO\n"; continue;}
        flag = true; int ttailcnt = 0; for (int i = n-1; i >= 0; i--) { if (s[i] == 'T') ttailcnt++; else { if (ttailcnt <= 0) { flag = false; break; } else ttailcnt--;}}
        int mcnt = 0; for (int i = 0; i < n; i++) {if (s[i] == 'M') mcnt++;}
        if (mcnt != n/3) flag = false;
        if (!flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}