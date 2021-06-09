#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;

const int maxn = 5e5+5;

int pd[maxn];
int pk[maxn];
int dp[maxn];

int gcd(int a, int b) {
    if (b == 0) return a;
    else if (a % b == 0) return b;
    else return gcd(b, a % b);
} 

int main() {
    int t; cin >> t;
    while (t--) {
        memset(pd,0,sizeof(pd));
        memset(pk,0,sizeof(pk));
        memset(dp,0,sizeof(dp));
        int n; cin >> n;
        string s; cin >> s;
        map<int,map<int,int>> m;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'D') {pd[i] = (i == 0? 0: pd[i-1]) + 1; pk[i] = (i == 0? 0: pk[i-1]);}
            if (s[i] == 'K') {pk[i] = (i == 0? 0: pk[i-1]) + 1; pd[i] = (i == 0? 0: pd[i-1]);}
        }
        for (int i = 0; i < s.length(); i++) {
            dp[i] = 1;
        }
        for (int i = 0; i < s.length(); i++) {
            int x = gcd(pd[i], pk[i]);
            //cout << pd[i] << " " << pk[i] << " " << x << endl;
            dp[i] = max(dp[i], m[pd[i]/x][pk[i]/x] + 1);
            if (i) cout << " ";
            cout << dp[i];
            m[pd[i]/x][pk[i]/x] = max(m[pd[i]/x][pk[i]/x], dp[i]);
        }
        cout << endl;
    }
    return 0; 
}