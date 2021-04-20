#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[2005];
long long dp[2005][2005];
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    for (int i = 0; i < n; i++) dp[i][i] = 0;
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n-k; i++) {
             // 自底向上有点难理解，但可以理解成轮换对称
            dp[i][i+k] = a[i+k] - a[i] + min(dp[i][i+k-1], dp[i+1][i+k]);
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}