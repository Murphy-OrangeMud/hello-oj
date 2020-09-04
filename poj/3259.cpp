#include <iostream>
#include <vector>
using namespace std;
const int inf = (1 << 30);
const int maxn = 505;
int n, m, w;
struct e {
    int s, t, w;
    e() {}
    e(int _s, int _t, int _w): s(_s), t(_t), w(_w) {}
    bool operator < (const e & other) const {
        return w > other.w;
    }
};
struct v {
    int num;
    int dist;
    vector<e> out;
    v() {
        dist = inf;
    }
}room[maxn];
bool bellman_ford(int v) {
    room[v].dist = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < room[i].out.size(); j++) {
                if (room[i].dist != inf) {
                    if (room[room[i].out[j].t].dist > room[i].dist + room[i].out[j].w) {
                        room[room[i].out[j].t].dist = room[i].dist + room[i].out[j].w;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < room[i].out.size(); j++) {
            if (room[room[i].out[j].t].dist > room[i].dist + room[i].out[j].w) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int f;
    scanf("%d", &f);
    for (int i = 0; i < f; i++) {
        scanf("%d%d%d", &n, &m, &w);
        for (int i = 1; i <= n; i++) {
            room[i].num = i;
            room[i].dist = inf;
            room[i].out.clear();
        }
        for (int j = 0; j < m; j++) {
            int cs, ee, t;
            scanf("%d%d%d", &cs, &ee, &t);
            room[cs].out.push_back(e(cs, ee, t));
            room[ee].out.push_back(e(ee, cs, t));
        }
        for (int j = 0; j < w; j++) {
            int cs, ee, t;
            scanf("%d%d%d", &cs, &ee, &t);
            room[cs].out.push_back(e(cs, ee, -t));
        }
        printf("%s\n", bellman_ford(1)? "YES": "NO");
    }
    return 0;
}
