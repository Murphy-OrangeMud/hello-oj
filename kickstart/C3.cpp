// 看了题解。类似于后缀数组的办法。
// WA: 没有开long long
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 100005;
const int offset = maxn * 101;
int sum[maxn];
int a[maxn];
int p[2*offset + 10];
int res[maxn];
bool perfect(int x) {
    if ((int)sqrt(x) == sqrt(x)) return true;
    return false;
}
void solve() {
    int n;
    cin >> n;
    memset(sum, 0, sizeof(sum));
    memset(p, 0, sizeof(p));
    memset(a, 0, sizeof(a));
    memset(res, 0, sizeof(res));
    long long cnt = 0;
    p[offset]++;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
        for (int j = 0; j <= sqrt(offset); j++) {
            res[i] += p[sum[i] - j*j + offset];
        }
        p[sum[i] + offset]++;
        cnt += res[i];
    }
    cout << cnt << endl;
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