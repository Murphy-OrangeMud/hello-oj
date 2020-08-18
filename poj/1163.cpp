#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
int triangle[maxn][maxn];
int dp[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (i == n - 1) {
                dp[j] = triangle[i][j];
            } else {
                dp[j] = max(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
    }
    cout << dp[0] << endl;
    return 0;
}