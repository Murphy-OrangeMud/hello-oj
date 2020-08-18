#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1005;
int d[maxn];
int a[maxn];
int main() {
    int n;
    cin >> n;
    memset(d, 1, sizeof(d));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    d[0] = 0;
    d[1] = a[0];
    for (int i = 1; i < n; i++) {
        int l = 0, r = i;
        int mid = (l + r) / 2;
        while (l <= r) {
            mid = (l + r) / 2;
            if (d[mid] < a[i] && d[mid + 1] >= a[i]) {
                d[mid + 1] = min(d[mid + 1], a[i]);
                break;
            }
            else if (d[mid] >= a[i]) {
                r = mid;
            } 
            else {
                l = mid + 1;
            }
        }
    }
    for (int i = n; i > 0; i--) {
        if (d[i] <= 10000) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}