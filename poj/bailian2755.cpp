#include <iostream>
using namespace std;
const int maxn = 25;
const int maxv = 45;
int dp[maxn][maxv];
int a[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 40; j++) {
            if (j >= a[i]) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j - a[i]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][40] << endl;
    return 0;
}