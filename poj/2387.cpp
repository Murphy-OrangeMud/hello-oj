#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1005;
const int inf = 0xffffff;
struct e {
    int start, end, weight;
    e(int _s, int _e, int _w): start(_s), end(_e), weight(_w) {}
};
struct v {
    vector<e> out;
    int num;
    int dist;
    int change;
    v () {}
    v(int _num): num(_num) {
        dist = inf;
        change = 0;
    }
    bool operator < (const v & other) const {
        return dist > other.dist;
    }
}vertices[maxn];
int m, n;
void spfa() {
    priority_queue<v> pq;
    vertices[1].dist = 0;
    pq.push(vertices[1]);
    v cur;
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();
        for (int i = 0; i < cur.out.size(); i++) {
            if (cur.dist + cur.out[i].weight < vertices[cur.out[i].end].dist) {
                vertices[cur.out[i].end].dist = cur.dist + cur.out[i].weight;
                vertices[cur.out[i].end].change++;
                pq.push(vertices[cur.out[i].end]);
            }
        }
    }
    cout << vertices[n].dist << endl;
}
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        vertices[i] = v(i);
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vertices[a].out.push_back(e(a, b, c));
        vertices[b].out.push_back(e(b, a, c));
    }
    spfa();
    return 0;
}