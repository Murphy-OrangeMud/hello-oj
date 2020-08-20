#include <iostream>
#include <vector>
using namespace std;
const int maxn = 104;
const int inf = 0xffffff;
int n;
int minlen = inf;
struct e {
    int start, end;
    int toll, len;
    e(){}
    e(int _s, int _e, int _t, int _l): start(_s), end(_e), toll(_t), len(_l) {}
};
struct v {
    int num;
    vector<e> out;
}vertices[maxn];
int visited[maxn][2];
void dfs(int city, int len, int money) {
    if (city == n) {
        minlen = min(len, minlen);
        return;
    }
    for (int i = 0; i < vertices[city].out.size(); i++) {
        if (money < vertices[city].out[i].toll) continue;
        if (len + vertices[city].out[i].len >= minlen) continue;
        if (visited[vertices[city].out[i].end][0] <= len + vertices[city].out[i].len && visited[vertices[city].out[i].end][1] >= money - vertices[city].out[i].toll) continue;
        visited[vertices[city].out[i].end][0] = len + vertices[city].out[i].len;
        visited[vertices[city].out[i].end][1] = money - vertices[city].out[i].toll;
        dfs(vertices[city].out[i].end, len + vertices[city].out[i].len, money - vertices[city].out[i].toll);
    }
}
int main() {
    int k, r;
    cin >> k >> n >> r;
    for (int i = 1; i <= n; i++) {
        vertices[i].num = i;
    }
    for (int i = 0; i < r; i++) {
        int s, d, l, t;
        cin >> s >> d >> l >> t;
        vertices[s].out.push_back(e(s, d, t, l));
    }
    dfs(1, 0, k);
    if (minlen == inf) cout << -1 << endl;
    else cout << minlen << endl;
    return 0;
}