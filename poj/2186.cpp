#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 10005;
struct v {
    int num;
    int color;
    int dfn, low;
    vector<int> out;
    v() {
        color = -1;
    }
}vertices[maxn];
int cnt = 1;
stack<int> stk;
int inpath[maxn];
int n, m;
int idx = 0;
int visited[maxn];
void tarjan(int u) {
    vertices[u].dfn = ++idx;
    vertices[u].low = idx;
    visited[u] = 1;
    inpath[u] = 1;
    stk.push(u);
    for (int i = 0; i < vertices[u].out.size(); i++) {
        int v = vertices[u].out[i];
        if (!visited[v]) {
            tarjan(v);
            vertices[u].low = min(vertices[u].low, vertices[v].low);
        } else {
            if (inpath[v]) {
                vertices[u].low = min(vertices[u].low, vertices[v].dfn);
            }
        }
    }
    if (vertices[u].dfn == vertices[u].low) {
        while (!stk.empty() && stk.top() != u) {
            vertices[stk.top()].color = cnt;
            inpath[stk.top()] = 0;
            stk.pop();
        }
        if (!stk.empty()) {
            vertices[stk.top()].color = cnt;
            inpath[stk.top()] = 0;
            stk.pop();
        }
        cnt++;
    }
}
struct p {
    int indeg;
    vector<int> vertices;
    vector<int> out;
} points[maxn];
void toposort() {
    queue<int> q;
    for (int i = 1; i <= cnt; i++) {
        if (points[i].indeg == 0) {
            q.push(i);
        }
    }
    int cur;
    int out = 0;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (points[cur].out.size() == 0) ++out;
        for (int i = 0; i < points[cur].out.size(); i++) {
            points[points[cur].out[i]].indeg--;
            if (points[points[cur].out[i]].indeg == 0) {
                q.push(points[cur].out[i]);
            }
        }
    }
    if (out > 1) cout << 0 << endl;
    else cout << points[cur].vertices.size() << endl;
}
int main() {
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= n; i++) {
        vertices[i].num = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        vertices[a].out.push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) tarjan(i);
    }
    if (!stk.empty()) {
        while (!stk.empty()) {
            vertices[stk.top()].color = cnt;
            stk.pop();
        }
        cnt++;
    }
    for (int i = 1; i <= n; i++) {
        points[vertices[i].color].vertices.push_back(i);
        for (int j = 0; j < vertices[i].out.size(); j++) {
            if (vertices[vertices[i].out[j]].color == vertices[i].color) continue;
            bool flag = false;
            for (int k = 0; k < points[vertices[i].color].out.size(); k++) {
                if (points[vertices[i].color].out[k] == vertices[vertices[i].out[j]].color) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                points[vertices[i].color].out.push_back(vertices[vertices[i].out[j]].color);
                points[vertices[vertices[i].out[j]].color].indeg++;
            }
        }
    }
    toposort();
    return 0;
}