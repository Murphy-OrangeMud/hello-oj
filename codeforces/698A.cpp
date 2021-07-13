#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 4 1 3 2 0
int main() {
    int n; cin >> n;
    int a[105];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) cin >> a[i];
    int dp[105][3];
    memset(dp, 1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        switch(a[i]) {
            case 0: {
                if (i == 0) dp[i][0] = 1;
                else {
                    for (int j = 0; j < 3; j++) {
                        dp[i][0] = min(dp[i][0], dp[i-1][j] + 1);
                    }
                }
                break;
            }
            case 1: {
                if (i == 0) {
                    dp[i][0] = 1;
                    dp[i][2] = 0;
                } else {
                    for (int j = 0; j < 3; j++) {
                        dp[i][0] = min(dp[i][0], dp[i-1][j] + 1);
                        if (j != 2) {
                            dp[i][2] = min(dp[i][2], dp[i-1][j]);
                        }
                    }
                }
                break;
            }
            case 2: {
                if (i == 0) {
                    dp[i][0] = 1;
                    dp[i][1] = 0;
                } else {
                    for (int j = 0; j < 3; j++) {
                        dp[i][0] = min(dp[i][0], dp[i-1][j] + 1);
                        if (j != 1) {
                            dp[i][1] = min(dp[i][1], dp[i-1][j]);
                        }
                    }
                }
                break;
            }
            case 3: {
                if (i == 0) {
                    dp[i][0] = 1;
                    dp[i][1] = 0;
                    dp[i][2] = 0;
                } else {
                    for (int j = 0; j < 3; j++) {
                        dp[i][0] = min(dp[i][0], dp[i-1][j] + 1);
                        if (j != 1) {
                            dp[i][1] = min(dp[i][1], dp[i-1][j]);
                        }
                        if (j != 2) {
                            dp[i][2] = min(dp[i][2], dp[i-1][j]);
                        }
                    }
                }
                break;
            }
        }
    }
    int minday = 105;
    for (int i = 0; i < 3; i++) {
        minday = min(minday, dp[n-1][i]);
    }
    cout << minday << endl;
    return 0;
}