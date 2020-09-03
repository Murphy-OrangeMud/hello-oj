//WA: 还没找到原因在哪
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 105;
int n, m;
int parent[maxn];
struct e {
    int start, end, weight;
    bool visited;
    int num;
    e() {}
    e(int _start, int _end, int _weight, int _num): start(_start), end(_end), weight(_weight), num(_num) {
        visited = false;
    }
    bool operator < (const e & other) const {
        return weight > other.weight;
    }
};
vector<e> edges;
int getroot(int a) {
    if (a != parent[a]) {
        parent[a] = getroot(parent[a]);
    }
    return parent[a];
}
void kruskal() {
    vector<e> ans;
    priority_queue<e> pq;
    for (int i = 0; i < edges.size(); i++) {
        pq.push(edges[i]);
    }
    int val = 0;
    while (!pq.empty()) {
        e cur = pq.top();
        pq.pop();
        int ps = getroot(cur.start);
        int pt = getroot(cur.end);
        //cout << "e: " << cur.start << " " << cur.end << " " << cur.weight << endl;
        if (ps == pt) continue;
        parent[pt] = ps;
        val += cur.weight;
        ans.push_back(cur);
        edges[cur.num].visited = true;
        //cout << "e: " << cur.start << " " << cur.end << " " << cur.weight << endl;
    }
    for (int i = 0; i < edges.size(); i++) {
        if (!edges[i].visited) {
            //cout << edges[i].start << " " << edges[i].end << " " << edges[i].weight << endl;
            edges[i].visited = true;
            for (int j = 0; j < edges.size(); j++) {
                if (j == i) continue;
                if (edges[j].visited && edges[j].weight == edges[i].weight) {
                    cout << "Not Unique!\n";
                    return;
                }
            }
            edges[i].visited = false;
        }
    }
    cout << val << endl;
    return;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < maxn; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < t; i++) {
        edges.clear();
        cin >> n >> m;
        for (int j = 0; j < m; j++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back(e(u, v, w, j));
        }
        kruskal();
    }
    return 0;
}