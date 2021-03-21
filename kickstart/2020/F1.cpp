#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100005;
struct people {
    int num;
    int round;
    people() {}
    people(int _num, int _round):num(_num), round(_round) {}
    bool operator < (const people & other) const {
        if (round < other.round) return true;
        else if (round == other.round) {
            return num < other.num;
        }
        return false;
    }
}p[maxn];
int a[maxn];
void solve() {
    memset(a, 0, sizeof(a));
    memset(p, 0, sizeof(p));
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++ ) {
        cin >> a[i];
        p[i].num = i;
        p[i].round = (a[i] % x == 0? a[i] / x: a[i] / x + 1);
    }
    sort(p+1, p+n+1);
    for (int i = 1; i <= n; i++) {
        cout << " " << p[i].num;
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ":";
        solve();
    }
    return 0;
}