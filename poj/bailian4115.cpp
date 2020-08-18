#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 205;
const int maxt = 15;
char maze[maxn][maxn];
int visited[maxn][maxn][maxt];
struct state {
    int x, y;
    int chakera;
    int step;
    state() {}
    state(int _x, int _y, int _step, int _chakera): x(_x), y(_y), step(_step), chakera(_chakera) {}
    bool operator < (const state & other) const {
        return step > other.step;
    }
};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int main() {
    int m, n, t;
    cin >> m >> n >> t;
    int sx, sy;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '@') {
                sx = i;
                sy = j;
            }
        }
    }
    priority_queue<state> pq;
    pq.push(state(sx, sy, 0, t));
    state cur;
    bool flag = false;
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();
        if (maze[cur.x][cur.y] == '+') {
            flag = true;
            cout << cur.step << endl;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nt = cur.chakera;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (maze[nx][ny] == '#') nt -= 1;
            if (nt < 0) continue;
            if (visited[nx][ny][nt]) continue;
            visited[nx][ny][nt] = 1;
            pq.push(state(nx, ny, cur.step + 1, nt));
        }
    }
    if (!flag) cout << -1 << endl;
    return 0;
}