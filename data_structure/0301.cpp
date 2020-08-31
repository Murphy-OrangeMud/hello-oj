#include <iostream>
#include <queue>
using namespace std;
struct state {
    int idx;
    int val;
    state() {}
    state(int _idx, int _val): idx(_idx), val(_val) {}
};
int main() {
    int n, k;
    cin >> n >> k;
    deque<state> maxq;
    deque<state> minq;
    vector<int> maxv;
    vector<int> minv;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        while (!maxq.empty() && maxq.front().idx <= i - k) maxq.pop_front();
        while (!maxq.empty() && maxq.back().val < v) maxq.pop_back();
        maxq.push_back(state(i, v));
        if (i >= k - 1) maxv.push_back(maxq.front().val);
        while (!minq.empty() && minq.front().idx <= i - k) minq.pop_front();
        while (!minq.empty() && minq.back().val > v) minq.pop_back();
        minq.push_back(state(i, v));
        if (i >= k - 1) minv.push_back(minq.front().val);
    }
    for (int i = 0; i < minv.size(); i++) {
        if (i) cout << " ";
        cout << minv[i];
    }
    cout << endl;
    for (int i = 0; i < maxv.size(); i++) {
        if (i) cout << " ";
        cout << maxv[i];
    }
    cout << endl;
    return 0;
}