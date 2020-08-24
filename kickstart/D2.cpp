#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxk = 1e4 + 5;
int a[maxk];
int f[maxk][4];
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        memset(f, 1, sizeof(f));
        memset(a, 0, sizeof(a));
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> a[j];
        }
        for (int j = 0; j < 4; j++) {
            f[0][j] = 0;
        }
        for (int j = 1; j < k; j++) {
            for (int l = 0; l < 4; l++) {
                for (int m = 0; m < 4; m++) {
                    if ((l >= m && a[j] < a[j-1]) 
                    || (l <= m && a[j] > a[j-1])
                    || (l != m && a[j] == a[j-1])) {
                        f[j][l] = min(f[j][l], f[j-1][m] + 1);
                    } else {
                        f[j][l] = min(f[j][l], f[j-1][m]);
                    }
                }
            }
        }
        int ans = 1e10;
        for (int j = 0; j < 4; j++) {
            ans = min(ans, f[k-1][j]);
        }
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
    return 0;
}