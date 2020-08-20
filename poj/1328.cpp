#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
struct island {
    double left, right;
    island() {}
    island(double _l, double _r): left(_l), right(_r) {}
    bool operator < (const island & other) const {
        if (right > other.right) return true;
        else if (right == other.right) {
            return left > other.left;
        }
        return false;
    }
};
int main() {
    int n, d;
    int kase = 0;
    while (cin >> n && n) {
        cin >> d;
        bool no = false;
        priority_queue<island> pq;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            pq.push(island(x-sqrt((double)(d*d-y*y)), x+sqrt((double)(d*d-y*y))));
            if (abs(y) > d) no = true;
        }
        if (no) {
            cout << "Case " << ++kase << ": " << -1 << endl;
            continue;
        }
        vector<double> cannon;
        island cur;
        while (!pq.empty()) {
            cur = pq.top();
            pq.pop();
            if (cannon.size() == 0) {
                cannon.push_back(cur.right);
            }
            else {
                if (cannon[cannon.size() - 1] >= cur.left) {
                    continue;
                } else {
                    cannon.push_back(cur.right);
                }
            }
        }
        cout << "Case " << ++kase << ": " << cannon.size() << endl;
    }
    return 0;
}