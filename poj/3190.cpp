#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
struct interval {
    int begin, end;
    int used;
    int num;
    interval(int _num, int _begin, int _end): num(_num), begin(_begin), end(_end) {
        used = false;
    }
    bool operator < (const interval & other) const {
        return end < other.end;
    }
    bool operator > (const interval & other) const {
        return num > other.num;
    }
};
int n;
int main() {
    cin >> n;
    vector<interval> intervals;
    for (int i = 0; i < n; i++) {
        int b, e;
        cin >> b >> e;
        intervals.push_back(interval(i, b, e));
    }
    sort(intervals.begin(), intervals.end());
    int used = 0;
    int cnt = 0;
    while (used < intervals.size()) {
        int curend = 0;
        ++cnt;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].begin <= curend) continue;
            if (intervals[i].used) continue;
            used++;
            intervals[i].used = cnt;
            curend = intervals[i].end;
        }
    }
    cout << cnt << endl;
    sort(intervals.begin(), intervals.end(), greater<interval>());
    for (int i = 0; i < intervals.size(); i++) {
        cout << intervals[i].used << endl;
    }
    return 0;
}