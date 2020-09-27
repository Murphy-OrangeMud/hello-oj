#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct interval {
    long long s, t;
    interval() {}
    interval(int _s, int _t): s(_s), t(_t) {}
    bool operator < (const interval & other) const {
        return s > other.s;
    }
};
void solve() {
    long long n, k;
    cin >> n >> k;
    priority_queue<interval> pq;
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        pq.push(interval(s, t));
    }
    long long curtime = 0;
    int deploy = 0;
    interval cur;
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();
        if (cur.t <= curtime) continue;
        int tmpdep = (cur.t - max(cur.s, curtime)) / k;
        if ((cur.t - max(cur.s, curtime)) % k) tmpdep++;
        deploy += tmpdep;
        curtime = max(curtime + tmpdep * k, cur.s + tmpdep * k);
    }
    cout << deploy << endl;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}
