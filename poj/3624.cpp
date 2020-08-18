#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 3405;
const int maxm = 12890;
int dp[maxm];
int w[maxn];
int d[maxn];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> d[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            if (j >= w[i]) {
                dp[j] = max(dp[j], dp[j-w[i]] + d[i]);
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= m; i++) {
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}