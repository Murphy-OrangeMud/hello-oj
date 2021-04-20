#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

void solve() {
    int n; cin >> n;
    string s;
    cin >> s;
    const int maxn = 2e5+5;
    int dp[maxn];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] > s[i-1]) dp[i] = dp[i-1]+1;
        else dp[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << " " << dp[i];
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ":";
        solve();
    }
    return 0;
}