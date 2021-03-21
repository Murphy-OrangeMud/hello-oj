#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 200005;
int a[maxn];
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        memset(a, 0, sizeof(a));
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        int cnt = 0;
        int maximum = -1;
        for (int j = 0; j < n; j++) {
            if (j == 0 && a[j] > a[j+1]) cnt++;
            else if (j < n-1 && a[j] > maximum && a[j] > a[j+1]) cnt++;
            else if (j == n-1 && a[j] > maximum) cnt++;
            maximum = max(maximum, a[j]);
        }
        cout << "Case #" << i+1 << ": " << cnt << endl;
    }
    return 0;
}