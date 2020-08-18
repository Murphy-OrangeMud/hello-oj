#include <iostream>
#include <queue>
using namespace std;
const int maxn = 100005;
int visited[maxn * 2];
struct state {
    int step;
    int x;
    state(){}
    state(int _x, int _step): x(_x), step(_step) {}
    bool operator < (const state & other) const {
        return step > other.step;
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    priority_queue<state> pq;
    state cur;
    pq.push(state(n, 0));
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();
        visited[cur.x] = true;
        if (cur.x == k) {
            cout << cur.step << endl;
            break;
        }
        if (cur.x >= 1 && !visited[cur.x-1]) {
            pq.push(state(cur.x-1, cur.step+1));
        }
        if (cur.x < maxn - 1 && !visited[cur.x+1]) {
            pq.push(state(cur.x+1, cur.step+1));
        }
        if (cur.x < maxn / 2 && !visited[cur.x*2]) {
            pq.push(state(cur.x*2, cur.step+1));
        }
    }
    return 0;
}