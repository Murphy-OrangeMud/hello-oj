#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int maxr = 35;
const int maxc = 35;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
struct v {
    char symbol;
    int in;
    vector<int> out;
} vertices[27];
struct state {
    string ans;
    int cur;
    state() {}
    state(string _ans, int _cur): ans(_ans), cur(_cur) {}
};
int r, c;
int visited[maxr][maxc];
char map[maxr][maxc];
int inuse[27];
void dfs(int x, int y, char name) {
    //cout << x << " " << y << " " << map[x][y] << endl;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ny < 0 || ny >= c || nx < 0 || nx >= r) continue;
        if (visited[nx][ny]) continue;
        if (map[nx][ny] == name) {
            dfs(nx, ny, name);
        }
        else {
            if (i == 0) {
                bool flag = true;
                for (int j = 0; j < vertices[map[x][y] - 'A'].out.size(); j++) {
                    if (vertices[map[x][y] - 'A'].out[j] == map[nx][ny] - 'A') {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    vertices[map[x][y] - 'A'].out.push_back(map[nx][ny] - 'A');
                    vertices[map[nx][ny] - 'A'].in++;
                }
            }
            if (i == 2) {
                bool flag = true;
                for (int j = 0; j < vertices[map[nx][ny] - 'A'].out.size(); j++) {
                    if (vertices[map[nx][ny] - 'A'].out[j] == map[x][y] - 'A') {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    vertices[map[nx][ny] - 'A'].out.push_back(map[x][y] - 'A');
                    vertices[map[x][y] - 'A'].in++;
                }
            }
        }
    }
}
void toposort() {
    int used[27];
    memset(used, 0, sizeof(used));
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (inuse[i] && vertices[i].in == 0) {
            q.push(i);
            used[i] = 1;
        }
    }
    string ans = "";
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans += vertices[cur].symbol;
        for (int i = 0; i < vertices[cur].out.size(); i++) {
            if (used[vertices[cur].out[i]]) continue;
            vertices[vertices[cur].out[i]].in--;
            if (vertices[vertices[cur].out[i]].in == 0) {
                used[vertices[cur].out[i]] = 1;
                q.push(vertices[cur].out[i]);
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (inuse[i] && !used[i]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
}
void solve() {
    cin >> r >> c;
    memset(visited, 0, sizeof(visited));
    memset(inuse, 0, sizeof(inuse));
    for (int i = 0; i < r; i++) {
        for (int j = 0;  j < c; j++) {
            cin >> map[i][j];
            inuse[map[i][j] - 'A'] = 1;
        }
    }
    for (int i = 0; i < 26; i++) {
        vertices[i].symbol = (char)(i + 'A');
        vertices[i].in = 0;
        vertices[i].out.clear();
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!visited[i][j]) dfs(i, j, map[i][j]);
        }
    }
    /*
    for (int i = 0; i < 26; i++) {
        cout << vertices[i].symbol << " ";
        for (int j = 0; j < vertices[i].out.size(); j++) {
            cout << (char)(vertices[i].out[j] + 'A') << " ";
        }
        cout << endl;
    }*/
    toposort();
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}