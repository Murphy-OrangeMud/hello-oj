#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxbudget = 100005;
const int maxn = 100005;
int n, b;
int a[maxn];
int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d%d", &n, &b);
        memset(a, 0, sizeof(a));
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
        sort(a, a + n);
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (b - a[j] < 0) break;
            b -= a[j];
            cnt++;
        }
        printf("Case #%d: %d\n", i, cnt);
    }
    return 0;
}