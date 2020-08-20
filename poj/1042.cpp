#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxt = 200;
const int maxn = 30;
int dp[maxn][maxt];
int f[maxn];
int d[maxn];
int t[maxn];
vector<int> path[maxn][maxt];
int main() {
    int n, h;
    while (cin >> n && n) {
        cin >> h;
        h *= 12;
        memset(f, 0, sizeof(f));
        memset(d, 0, sizeof(d));
        memset(t, 0, sizeof(t));
        memset(dp, 0, sizeof(dp));
        memset(path, 0, sizeof(path));
        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        for (int i = 0; i < n-1; i++) {
            cin >> t[i];
        }
        dp[0][0] = 0;
        //path[0][0].push_back(0);
        for (int i = 1; i <= h; i++) {
            dp[0][i] = dp[0][i-1] + max(f[0] - d[0] * (i-1), 0);
            path[0][i].push_back(i);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= h; j++) {
                if (j <= t[i-1]) continue;
                for (int k = t[i-1] + 1; k < j; k++) {
                    int fish = min(f[i] * ((f[i] + d[i]) / d[i] + 1) / 2, (k - t[i-1]) * f[i] - (k - t[i-1]) * (k - t[i-1] - 1) / 2 * d[i]);
                    if (dp[i][j] < dp[i-1][j - k] + fish) {
                        dp[i][j] = dp[i-1][j - k] + fish;
                        path[i][j] = path[i-1][j-k];
                        path[i][j].push_back(k-t[i-1]);
                    } else if (dp[i][j] == dp[i-1][j-k] + fish) {
                        for (int l = 0; l < path[i-1][j-k].size(); l++) {
                            if (path[i-1][j-k][l] > path[i][j][l]) {
                                path[i][j] = path[i-1][j-k];
                                path[i][j].push_back(k-t[i-1]);
                                break;
                            }
                            else if (path[i-1][j-k][l] < path[i][j][l]) {
                                break;
                            }
                        }
                    }
                }
            }
        }
        int maximum = 0;
        int i0 = 0;
        for (int i = 0; i < n; i++) {
            if (maximum < dp[i][h]) {
                maximum = dp[i][h];
                i0 = i;
            }
        }
        for (int i = 0; i < path[i0][h].size(); i++) {
            if (i) cout << ", ";
            cout << path[i0][h][i] * 5;
        }
        for (int i = path[i0][h].size(); i < n; i++) {
            cout << ", 0";
        }
        cout << endl;
        cout << "Number of fish expected: " << dp[i0][h] << endl << endl;
    }
    return 0;
}