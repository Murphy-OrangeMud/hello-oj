// WA: 还没找到原因在哪
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 105;
int n, m;
struct e {
    bool valid;
    int start, end;
    int weight;
    e(int _s, int _t, int _w): start(_s), end(_t), weight(_w) {
        valid = true;
    }
    bool operator < (const e & other) const {
        if (weight > other.weight) return true;
        else if (weight == other.weight) {
            if (start > other.start) return true;
            else if (start == other.start) return end > other.end;
        }
        return false;
    }
};
struct v {
    int num;
    bool visited;
    vector<e> out;
} vertices[maxn];
vector<e> ans;
long long prim(bool first) {
    for (int i = 1; i <= n; i++) {
        vertices[i].visited = false;
    }
    priority_queue<e> pq;
    int cur = 1;
    vertices[cur].visited = true;
    for (int i = 0; i < vertices[cur].out.size(); i++) {
        if (!vertices[cur].out[i].valid) continue;
        pq.push(vertices[cur].out[i]);
    }  
    long long val = 0;
    while (!pq.empty()) {
        e choice = pq.top();
        pq.pop();
        if (vertices[choice.end].visited) continue;
        else if (!choice.valid) continue;
        else {
            //test
            //cout << choice.start << " " << choice.end << " " << choice.weight << endl;
            vertices[choice.end].visited = true;
            val += choice.weight;
            if (first) ans.push_back(choice);
            for (int i = 0; i < vertices[choice.end].out.size(); i++) {
                if (!vertices[vertices[choice.end].out[i].end].visited) {
                    if (!vertices[choice.end].out[i].valid) continue;
                    pq.push(vertices[choice.end].out[i]);
                }
            }
        }
    }
    return val;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        ans.clear();
        for (int i = 1; i <= n; i++) {
            vertices[i].num = i;
            vertices[i].visited = false;
            vertices[i].out.clear();
        }
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            vertices[u].out.push_back(e(u, v, w));
            vertices[v].out.push_back(e(v, u, w));
        }
        long long minw = prim(true);
        bool unique = true;
        for (int i = 0; i < ans.size(); i++) {
            //test
            //cout << ans[i].start << " " << ans[i].end << " " << ans[i].weight << endl;
            for (int j = 0; j < vertices[ans[i].start].out.size(); j++) {
                if (vertices[ans[i].start].out[j].end == ans[i].end && vertices[ans[i].start].out[j].weight == ans[i].weight) {
                    vertices[ans[i].start].out[j].valid = false;
                    break;
                }
            }
            for (int j = 0; j < vertices[ans[i].end].out.size(); j++) {
                if (vertices[ans[i].end].out[j].end == ans[i].start && vertices[ans[i].end].out[j].weight == ans[i].weight) {
                    vertices[ans[i].end].out[j].valid = false;
                    break;
                }
            }
            long long w = prim(false);
            if (w == minw) {
                cout << "Not Unique!" << endl;
                unique = false;
                break;
            }
            for (int j = 0; j < vertices[ans[i].start].out.size(); j++) {
                if (vertices[ans[i].start].out[j].end == ans[i].end && vertices[ans[i].start].out[j].weight == ans[i].weight) {
                    vertices[ans[i].start].out[j].valid = true;
                    break;
                }
            }
            for (int j = 0; j < vertices[ans[i].end].out.size(); j++) {
                if (vertices[ans[i].end].out[j].end == ans[i].start && vertices[ans[i].end].out[j].weight == ans[i].weight) {
                    vertices[ans[i].end].out[j].valid = true;
                    break;
                }
            }
        }
        if (unique) cout << minw << endl;
    }
    return 0;
}