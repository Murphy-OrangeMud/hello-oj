#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 3e5+5;
int a[maxn];

void solve() {
    int n; cin >> n;
    memset(a,0,sizeof(a));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int dph0[maxn]; int dpt0[maxn]; int dp[maxn]; 
    memset(dph0,0,sizeof(dph0));
    memset(dpt0,0,sizeof(dpt0));
    memset(dp,0,sizeof(dp));
    dph0[0] = 1; dph0[1] = 2;
    for (int i = 2; i < n; i++) {
        if (a[i] - a[i-1] == a[i-1] - a[i-2]) dph0[i] = dph0[i-1] + 1;
        else dph0[i] = 2; 
    }
    dpt0[n-1] = 1; dpt0[n-2] = 2;
    for (int i = n-3; i >= 0; i--) {
        if (a[i+1] - a[i] == a[i+2] - a[i+1]) dpt0[i] = dpt0[i+1] + 1;
        else dpt0[i] = 2;
    }
    dp[0] = dpt0[1] + 1;
    dp[n-1] = dph0[n-2] + 1;
    for (int i = 1; i < n - 1; i++) {
        if (i < n-2 && a[i+1] - a[i-1] == 2 * (a[i+2] - a[i+1])) {
            if (i >= 2 && a[i+2]-a[i+1] == a[i-1] - a[i-2]) {
                dp[i] = max(dp[i], dph0[i-1] + dpt0[i+1] + 1);
            } else {
                dp[i] = max(dp[i], dpt0[i+1] + 2);
            }
        }
        if (i >= 2 && a[i+1] - a[i-1] == 2 * (a[i-1] - a[i-2])) {
            if (i >= 2 && a[i+2]-a[i+1] == a[i-1] - a[i-2]) {
                dp[i] = max(dp[i], dph0[i-1] + dpt0[i+1] + 1);
            } else {
                dp[i] = max(dp[i], dph0[i-1] + 2);
            }
        }
        dp[i] = max(dp[i], max(dph0[i-1]+1, dpt0[i+1]+1));
    }
    int maximum = 0;
    for (int i = 0; i < n; i++) {
        maximum = max(maximum, max(dp[i], max(dph0[i], dpt0[i])));
    }
    cout << " " << maximum << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ":";
        solve();
    }
    return 0;
}