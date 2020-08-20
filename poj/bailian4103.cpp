//踩方格
#include <iostream>
using namespace std;
const int maxn = 50;
int visited[maxn][maxn];
int dx[] = {0, 0, -1};
int dy[] = {1, -1, 0};
int n;
int cnt;
void dfs(int x, int y, int step) {
    if (step == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visited[nx][ny]) continue;
        visited[nx][ny] = 1;
        dfs(nx, ny, step + 1);
        visited[nx][ny] = 0;
    }
}
int main() {
    cin >> n;
    visited[24][24] = 1;
    dfs(24, 24, 0);
    cout << cnt << endl;
    return 0;
}