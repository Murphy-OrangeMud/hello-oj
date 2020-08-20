// add jianzhi: 看过题解之后加上的剪枝。替换掉第一根/最后一根木棍是没用的；跳过相同且没用过的木棍。
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 70;
struct stick {
    int used;
    int len;
    stick(){}
    stick(int _len): len(_len) {
        used = false;
    }
    bool operator < (const stick & other) const {
        return len > other.len;
    }
}sticks[maxn];
int n;
int dfs(int curlen, int goallen, int sticknum, int beginnum) {
    if (curlen == goallen) {
        return dfs(0, goallen, sticknum + 1, 0);
    }
    bool finished = true;
    for (int i = beginnum; i < n; i++) {
        if (sticks[i].used) continue;
        finished = false;
        // add jianzhi
        if (i > 0 && sticks[i-1].used == false && sticks[i].len == sticks[i-1].len) continue;
        if (curlen + sticks[i].len > goallen) continue;
        sticks[i].used = true;
        if (dfs(curlen + sticks[i].len, goallen, sticknum, i + 1) == false) {
            sticks[i].used = false;
            // add jianzhi
            if (curlen + sticks[i].len == goallen || curlen == 0) {
                return false;
            }
        } else {
            return true;
        }
    }
    if (finished && curlen != 0) {
        return false;
    }
    return finished;
}
int main() {
    while (cin >> n && n) {
        memset(sticks, 0, sizeof(sticks));
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> sticks[i].len;
            sum += sticks[i].len;
        }
        sort(sticks, sticks + n);
        for (int i = sticks[0].len; ; i++) {
            if (sum % i) continue;
            // add jianzhi
            if (i > sum / 2) {
                cout << sum << endl;
                break;
            }
            if (dfs(0, i, 0, 0)) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}