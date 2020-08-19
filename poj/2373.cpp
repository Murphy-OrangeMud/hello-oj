// WA原因：在f[i] == inf时表明这个点不能放水池，因此就算它是inf也不能push进去。
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxl = 1000005;
const int maxn = 1005;
const int inf = 0xffffff;
int cows[maxl];
int cowspoint[maxl];
int s[maxn];
int e[maxn];
int f[maxl];
struct state {
    int x, f;
    state(){}
    state(int _x, int _f): x(_x), f(_f) {}
    bool operator < (const state & other) const {
        return f > other.f;
    }
};
int main() {
    int n, l, a, b;
    cin >> n >> l >> a >> b;
    a *= 2; b *= 2;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
        cowspoint[s[i] + 1]++;
        cowspoint[e[i]]--;
    }
    cows[0] = cowspoint[0];
    f[0] = inf;
    for (int i = 1; i <= l; i++) {
        f[i] = inf;
        cows[i] = cows[i-1] + cowspoint[i];
    }
    priority_queue<state> pq;
    for (int i = a; i <= b; i += 2) {
        if (cows[i]) continue;
        f[i] = 1;
        if (i > b + 2 - a) continue;
        pq.push(state(i, f[i]));
    }
    for (int i = b + 2; i <= l; i += 2) {
        while (!pq.empty() && pq.top().x < i - b) pq.pop();
        if (!pq.empty()) {
            if (!cows[i]) {
                f[i] = pq.top().f + 1;
            }
        }
        if (f[i - a + 2] != inf)
            pq.push(state(i - a + 2, f[i - a + 2]));
    }
    if (f[l] == inf) cout << -1 << endl;
    else cout << f[l] << endl;
    return 0;
}