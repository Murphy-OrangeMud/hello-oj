#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 100005;
int sum[maxn];
int dp[maxn];
int a[maxn];
bool perfect(int x) {
    if ((int)sqrt(x) == sqrt(x)) return true;
    return false;
}
void solve() {
    int n;
    cin >> n;
    memset(sum, 0, sizeof(sum));
    memset(dp, 0, sizeof(dp));
    memset(a, 0, sizeof(a));
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (perfect(sum[i] - sum[j])) ++cnt;
        }
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