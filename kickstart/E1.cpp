#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200005;
int a[maxn];
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        memset(a, -1, sizeof(a));
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        int start = 0, end = 1, diff = a[1] - a[0], maxlen = 2;
        while (end < n) {
            if (a[end] - a[end - 1] == diff) {
                end++;
            } else {
                maxlen = max(maxlen, end - start);
                start = end - 1;
                diff = a[end] - a[end - 1];
            }
        }
        maxlen = max(maxlen, end - start);
        cout << "Case #" << i + 1 << ": " << maxlen << endl;
    }
    return 0;
}