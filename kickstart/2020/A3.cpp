//TLE: dp解法。复杂度O(n^2)。用二分可以做到O(nlogn)
//WA: 应该输出minint而不是mid
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int n, k;
int func() {
    int maxint = a[n-1] - a[0];
    int minint = 1;
    int mid;
    while (minint < maxint) {
        int kk = 0;
        mid = (maxint + minint) / 2;
        //cout << mid << endl;
        for (int i = 1; i < n; i++) {
            kk += (a[i] - a[i-1] - 1) / mid;
        }
        if (kk <= k) {
            maxint = mid;
        } else {
            minint = mid + 1;
        }
    }
    return minint;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        memset(a, 0, sizeof(a));
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        cout << "Case #" << i+1 << ": " << func() << endl;
    }
    return 0;
}
