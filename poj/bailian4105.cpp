#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 205;
const int maxk = 5;
struct state {
    int jewel;
    int step;
    int x, y;
    state() {}
    state(int _x, int _y, int _step, int _jewel): x(_x), y(_y), step(_step), jewel(_jewel) {}
    bool operator < (const state & other) const {
        return step > other.step;
    }
};
char maze[maxn][maxn];
int visited[maxn][maxn][35];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
priority_queue<state> pq;
vector<pair<int,int>> transfer;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c, k;
        cin >> r >> c >> k;
        memset(maze, 0, sizeof(maze));
        memset(visited, 0, sizeof(visited));
        transfer.clear();
        int sx, sy;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> maze[i][j];
                if (maze[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                if (maze[i][j] == '$') {
                    transfer.push_back(make_pair(i, j));
                }
            }
        }
        while (!pq.empty()) pq.pop();
        pq.push(state(sx, sy, 0, 0));
        state cur;
        bool flag = false;
        while (!pq.empty()) {
            cur = pq.top();
            pq.pop();
            if (maze[cur.x][cur.y] == 'E' && cur.jewel == (1 << k) - 1) {
                cout << cur.step << endl;
                flag = true;
                break;
            }
            int nx, ny, nk;
            for (int i = 0; i < 4; i++) {
                nx = cur.x + dx[i];
                ny = cur.y + dy[i];
                nk = cur.jewel;
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (maze[nx][ny] >= '0' && maze[nx][ny] <= '9') {
                    nk |= (1 << (maze[nx][ny] - '0'));
                }
                if (visited[nx][ny][nk]) continue;
                if (maze[nx][ny] == '#') continue;
                visited[nx][ny][nk] = 1;
                pq.push(state(nx, ny, cur.step + 1, nk));
            }
            if (maze[cur.x][cur.y] == '$') {
                for (int i = 0; i < transfer.size(); i++) {
                    nx = transfer[i].first;
                    ny = transfer[i].second;
                    if (nx == cur.x && ny == cur.y) continue;
                    if (visited[nx][ny][cur.jewel]) continue;
                    visited[nx][ny][cur.jewel] = 1;
                    pq.push(state(nx, ny, cur.step, cur.jewel));
                }
            }
        }
        if (!flag) {
            cout << "oop!" << endl;
        }
    }
    return 0;
}