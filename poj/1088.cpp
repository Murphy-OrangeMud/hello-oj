#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
const int maxh = 10005;
int map[maxn][maxn];
int dp[maxn][maxn];
int visited[maxn][maxn];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int treedp(int x, int y) {
    if (dp[x][y] > 0) {
        return dp[x][y];
    }
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (map[nx][ny] >= map[x][y]) continue;
        dp[x][y] = max(treedp(nx, ny) + 1, dp[x][y]);
    }
    return dp[x][y];
}
int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i <= m + 1; i++) {
        map[i][0] = maxh;
        map[i][n+1] = maxh;
    }
    for (int i = 0; i <= n + 1; i++) {
        map[0][i] = maxh;
        map[m+1][i] = maxh;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            treedp(i, j);
        }
    }
    int maxpath = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            maxpath = max(maxpath, dp[i][j]);
        }
    }
    cout << maxpath << endl;
    return 0;
}