// WA 点：奶牛应该按开始时间排序而不是结束时间排序
// 反例数据：
// 5 
// 1 10 
// 2 3 
// 3 4 
// 5 8 
// 4 9
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
struct interval {
    int begin, end;
    int used;
    int num;
    interval(int _num, int _begin, int _end): num(_num), begin(_begin), end(_end) {
        used = 0;
    }
    bool operator < (const interval & other) const {
        return begin < other.begin;
    }
    bool operator > (const interval & other) const {
        return num > other.num;
    }
};
struct stall {
    int num;
    int curend;
    stall() {}
    stall(int _num, int _curend): num(_num), curend(_curend) {}
    bool operator < (const stall & other) const {
        return curend > other.curend;
    }
};
int n;
int main() {
    cin >> n;
    vector<interval> intervals;
    for (int i = 1; i <= n; i++) {
        int b, e;
        cin >> b >> e;
        intervals.push_back(interval(i, b, e));
    }
    sort(intervals.begin(), intervals.end());
    priority_queue<stall> pq;
    int cnt = 0;
    stall cur;
    for (int i = 0; i < intervals.size(); i++) {
        if (!pq.empty()) {
            cur = pq.top();
            if (cur.curend >= intervals[i].begin) {
                ++cnt;
                pq.push(stall(cnt, intervals[i].end));
                intervals[i].used = cnt;
            } else {
                pq.pop();
                pq.push(stall(cur.num, intervals[i].end));
                intervals[i].used = cur.num;
            }
        } else {
            ++cnt;
            pq.push(stall(cnt, intervals[i].end));
            intervals[i].used = cnt;
        }
        //cout << intervals[i].begin << " " << intervals[i].end << " " << intervals[i].used << endl;
    }
    cout << cnt << endl;
    sort(intervals.begin(), intervals.end(), greater<interval>());
    for (int i = intervals.size() - 1; i >= 0; i--) {
        cout << intervals[i].used << endl;
    }
    return 0;
}