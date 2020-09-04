// TLE: 
#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 30005;
const int inf = (1 << 30);
int n, m;
struct e {
    int start, end;
    int weight;
    e() {}
    e(int _start, int _end, int _weight): start(_start), end(_end), weight(_weight) {}
    bool operator < (const e & other) const {
        return weight > other.weight;
    }
};
struct v {
    int num;
    bool visited;
    int dist;
    vector<e> out;
    v() {
        visited = false;
        dist = inf;
    }
    bool operator < (const v & other) const {
        return dist > other.dist;
    }
}child[maxn];
void dijkstra() {
    priority_queue<v> pq;
    child[1].dist = 0;
    pq.push(child[1]);
    while (!pq.empty()) {
        v cur = pq.top();
        pq.pop();
        if (child[cur.num].visited) continue;
        child[cur.num].visited = true;
        if (cur.num == n) {
            printf("%d\n", cur.dist);
            return;
        }
        for (int i = 0; i < cur.out.size(); i++) {
            if (child[cur.out[i].end].visited) continue;
            if (child[cur.out[i].end].dist > cur.dist + cur.out[i].weight) {
                child[cur.out[i].end].dist = cur.dist + cur.out[i].weight;
            }
            pq.push(child[cur.out[i].end]);
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        child[i].num = i;
    }
    for (int i = 0; i < m; i++) {
        int s, t, w;
        scanf("%d%d%d", &s, &t, &w);
        child[s].out.push_back(e(s, t, w));
    }
    dijkstra();
    return 0;
}