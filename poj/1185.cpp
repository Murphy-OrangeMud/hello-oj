#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
const int maxst = 1030;
const int maxm = 12;
int dp[maxn][maxst][maxst];
char map[maxn][maxm];
int n, m;
int countone(int state) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if ((state >> i) & 1) cnt++;
    }
    return cnt;
}
int legal(int row, int state) {
    for (int i = 0; i < m; i++) {
        if ((state >> i) & 1) {
            if (map[row][i] == 'H') return false;
            if (i > 0 && ((state >> (i-1)) & 1)) return false;
            if (i > 1 && ((state >> (i-2)) & 1)) return false;
            if (i < m-2 && ((state >> (i+2)) & 1)) return false;
            if (i < m-1 && ((state >> (i+1)) & 1)) return false;
        }
    }
    return true;
}
int func() {
    int maxstate = (1 << m);
    for (int i = 0; i < maxstate; i++) {
        if (!legal(0,i)) continue;
        for (int j = 0; j < maxstate; j++) {
            if (!legal(0,j)) continue;
            if (i & j) continue;
            dp[0][i][j] = countone(j);
        }
    }
    for (int i = 0; i < maxstate; i++) {
        if (!legal(1, i)) continue;
        for (int j = 0; j < maxstate; j++) {
            if (!legal(0, j)) continue;
            if (i & j) continue;
            dp[1][j][i] = dp[0][0][j] + countone(i);
        }
    }
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < maxstate; j++) {
            if (!legal(i,j)) continue;
            for (int k = 0; k < maxstate; k++) {
                if (!legal(i-1,k)) continue;
                if (j & k) continue;
                for (int l = 0; l < maxstate; l++) {
                    if (!legal(i-2, l)) continue;
                    if (k & l) continue;
                    if (l & j) continue;
                    dp[i][k][j] = max(dp[i][k][j], dp[i-1][l][k] + countone(j));
                    //cout << i << " " << l << " " << k << " " << j << " " << dp[i][k][j] << endl;
                }
            }
        }
    }
    int maximum = 0;
    for (int i = 0; i < maxstate; i++) {
        for (int j = 0; j < maxstate; j++) {
            if (maximum < dp[n-1][i][j]) {
                maximum = max(maximum, dp[n-1][i][j]);
            }
        }
    }
    return maximum;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    cout << func() << endl;
    return 0;
}