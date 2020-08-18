#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 6;
int maze[maxn][maxn];
struct state {
    int x, y;
    int step;
    vector<pair<int,int>> path;
    state() {}
    state(int _x, int _y, int _step): x(_x), y(_y), step(_step) {}
    state(int _x, int _y, int _step, vector<pair<int,int>>& vec): x(_x), y(_y), step(_step) {
        for (int i = 0; i < vec.size(); i++) {
            path.push_back(vec[i]);
        }
    }
    bool operator < (const state & other) const {
        return step > other.step;
    }
};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int visited[6][6];
int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> maze[i][j];
        }
    }
    priority_queue<state> pq;
    vector<pair<int,int>> vec;
    pq.push(state(0, 0, 0, vec));
    state cur;
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();
        vector<pair<int,int>> tmp;
        for (int i = 0; i < cur.path.size(); i++) {
            tmp.push_back(cur.path[i]);
        }
        tmp.push_back(make_pair(cur.x, cur.y));
        visited[cur.x][cur.y] = true;
        if (cur.x == 4 && cur.y == 4) {
            for (int i = 0; i < tmp.size(); i++) {
                cout << "(" << tmp[i].first << ", " << tmp[i].second << ")" << endl;
            }
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (visited[nx][ny]) continue;
            if (maze[nx][ny] == 1) continue;
            pq.push(state(nx, ny, cur.step + 1, tmp));
        }
    }
    return 0;
}