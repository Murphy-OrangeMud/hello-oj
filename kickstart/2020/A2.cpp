#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 55;
const int maxk = 35;
int dp[maxn][maxn * maxk];
int plate[maxn][maxk];
int sum[maxn][maxk];
int n, k, p;
int main() {
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        memset(dp, 0, sizeof(dp));
        memset(plate, 0, sizeof(plate));
        memset(sum ,0, sizeof(sum));
        scanf("%d%d%d", &n,&k,&p);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                scanf("%d", &plate[i][j]);
                sum[i][j] = sum[i][j-1] + plate[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= p; j++) {
                for (int l = 0; l <= k; l++) {
                    if (j >= l) {
                        dp[i][j] = max(dp[i][j], dp[i-1][j-l] + sum[i][l]);
                    }
                }
            }
        }
        printf("Case #%d: %d\n", tt, dp[n][p]);
    }
    return 0;
}