#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int dp[maxn][maxn];
int main() {
    string a, b;
    while (cin >> a >> b) {
        int lena = a.length();
        int lenb = b.length();
        memset(dp, 0, sizeof(dp));
        dp[0][0] = (a[0] == b[0]);
        for (int i = 1; i < lena; i++) {
            if (a[i] == b[0]) {
                dp[i][0] = 1;
            } else {
                dp[i][0] = dp[i-1][0];
            }
        }
        for (int i = 1; i < lenb; i++) {
            if  (a[0] == b[i]) {
                dp[0][i] = 1;
            } else {
                dp[0][i] = dp[0][i-1];
            }
        }
        for (int i = 1; i < lena; i++) {
            for (int j = 1; j < lenb; j++) {
                if (a[i] == b[j]) {
                    dp[i][j] = max(dp[i-1][j-1] + 1, max(dp[i][j-1], dp[i-1][j]));
                } else {
                    dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                }
            }
        }
        cout << dp[lena - 1][lenb - 1] << endl;
    }
    return 0;
}