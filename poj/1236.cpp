// WA/RE: 可能是不连通图！注意原本就是强连通图的情况
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 105;
struct v {
    int low, dfn, color, num;
    vector<int> out;
    v() { color = -1; }
}vertices[maxn];
struct p {
    vector<int> vertices;
    vector<int> out;
    int indeg;
}points[maxn];
int idx = 0;
int cnt = 1;
int n;
stack<int> stk;
int visited[maxn];
int inpath[maxn];
void tarjan(int u) {
    vertices[u].dfn = ++idx;
    vertices[u].low = idx;
    stk.push(u);
    inpath[u] = 1;
    visited[u] = 1;
    for (int i = 0; i < vertices[u].out.size(); i++) {
        int v = vertices[u].out[i];
        if (!visited[v]) {
            tarjan(v);
            vertices[u].low = min(vertices[u].low, vertices[v].low);
        }
        else {
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
void make_dag() {
    for (int i = 1; i <= n; i++) {
        int newidx = vertices[i].color;
        points[newidx].vertices.push_back(i);
        for (int k = 0; k < vertices[i].out.size(); k++) {
            if (vertices[vertices[i].out[k]].color == newidx) continue;
            bool flag = true;
            for (int j = 0; j < points[newidx].out.size(); j++) {
                if (vertices[vertices[i].out[k]].color == points[newidx].out[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                points[newidx].out.push_back(vertices[vertices[i].out[k]].color);
                points[vertices[vertices[i].out[k]].color].indeg++;
            }
        }
    }
}
void toposort() {
    if (cnt == 2) {
        cout << 1 << endl << 0 << endl;
        return;
    }
    queue<p> q;
    p cur;
    int in = 0;
    for (int i = 1; i < cnt; i++) {
        if (points[i].indeg == 0) {
            q.push(points[i]);
            ++in;
        }
    }
    int out = 0;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur.out.size() == 0) ++out;
        for (int i = 0; i < cur.out.size(); i++) {
            points[cur.out[i]].indeg--;
            if (points[cur.out[i]].indeg == 0) {
                q.push(points[cur.out[i]]);
            }
        }
    }
    cout << in << endl << max(in, out) << endl;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        vertices[i].num = i;
        int x;
        while (cin >> x && x)  {
            vertices[i].out.push_back(x);
        }
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
    make_dag();
    toposort();
    return 0;
}