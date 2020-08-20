#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct interval {
    int begin, end;
    interval(int _begin, int _end): begin(_begin), end(_end) {}
    bool operator < (const interval & other) const {
        return end < other.end;
    }
};
int main() {
    int n;
    while (cin >> n && n) {
        int b, e;
        vector<interval> intervals;
        for (int i = 0; i < n; i++) {
            cin >> b >> e;
            intervals.push_back(interval(b, e));
        }
        sort(intervals.begin(), intervals.end());
        int currentend = 0;
        int cnt = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].begin < currentend) continue;
            currentend = intervals[i].end;
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}