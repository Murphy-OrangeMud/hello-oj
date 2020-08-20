#include <iostream>
using namespace std;
const int maxn = 55;
int map[maxn][maxn];
int visited[maxn][maxn];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int m, n;
int maxarea;
int cnt = 0;
void dfs(int x, int y, int area) {
    //maxarea = max(maxarea, area);
    //cout << x << " " << y << " " << area << endl;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if (visited[nx][ny]) continue;
        if (map[x][y] & (1 << i)) continue;
        visited[nx][ny] = cnt;
        dfs(nx, ny, area + 1);
    }
}
int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                cnt++;
                dfs(i, j, 1);
            }
        }
    }
    for (int i = 1; i <= cnt; i++) {
        int area = 0;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (visited[x][y] == i) area++;
            }
        }
        maxarea = max(maxarea, area);
    }
    cout << cnt << endl << maxarea << endl;
    return 0;
}