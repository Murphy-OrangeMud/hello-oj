#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 105;
int a[maxn];
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        int cnt = 0;
        for (int j = 1; j < n-1; j++) {
            if (a[j] > a[j-1] && a[j] > a[j+1]) cnt++;
        }
        cout << "Case #" << i+1 << ": " << cnt << endl;
    }
    return 0;
}