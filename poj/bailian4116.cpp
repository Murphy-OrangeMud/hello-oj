#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 205;
struct state {
    int x, y;
    int step;
    state() {}
    state(int _x, int _y, int _step): x(_x), y(_y), step(_step) {}
    bool operator < (const state & other) const {
        return step > other.step;
    }
};
int visited[maxn][maxn];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char maze[maxn][maxn];
int main() {
    int s;
    cin >> s;
    for (int i = 0; i < s; i++) {
        memset(visited, -1, sizeof(visited));
        int m, n;
        cin >> n >> m;
        int sx, sy, ex, ey;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> maze[i][j];
                if (maze[i][j] == 'r') {
                    sx = i;
                    sy = j;
                }
                if (maze[i][j] == 'a') {
                    ex = i;
                    ey = j;
                }
            }
        }
        bool flag = false;
        priority_queue<state> pq;
        state cur;
        visited[sx][sy] = 0;
        pq.push(state(sx, sy, 0));
        while (!pq.empty()) {
            cur = pq.top();
            pq.pop();
            if (cur.x == ex && cur.y == ey) {
                cout << cur.step << endl;
                flag = true;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (visited[nx][ny] != -1) continue;
                // if (visited[nx][ny] != -1 && visited[nx][ny] <= cur.step) continue;
                if (maze[nx][ny] == '#') continue;
                if (maze[nx][ny] == 'x') {
                    visited[nx][ny] = cur.step + 2;
                    pq.push(state(nx, ny, cur.step + 2));
                } else {
                    visited[nx][ny] = cur.step + 1;
                    pq.push(state(nx, ny, cur.step + 1));
                }
            }
        }
        if (!flag) cout << "Impossible" << endl;
    }
    return 0;
}