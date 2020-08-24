#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 105;
const int minv = -128*100;
int matrix[maxn][maxn];
int dp[maxn][maxn]; //dp[i][j]: 在右边的x坐标为i的所有矩阵中的最大值
int sum[maxn][maxn]; //sum[i][j]: 从（0,0）到（i,j）的矩阵的和
int n;
void init() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int v; 
            scanf("%d", &v);
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + v;
        }
    }
}
int func() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 0; l < i; l++) {
                for (int k = 0; k < j; k++) {
                    dp[i][j] = max(dp[i][j], -sum[i][k] - sum[l][j] + sum[i][j] + sum[l][k]);
                }
            }
        }
    }
    int maximum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            maximum = max(maximum, dp[i][j]);
        }
    }
    return maximum;
}
int main() {
    init();
    cout << func() << endl;
    return 0;
}