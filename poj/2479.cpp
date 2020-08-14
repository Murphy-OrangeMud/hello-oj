#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int t;
int n;
const long long maxn = 50005;
long long a[maxn];
long long bsum[maxn];
long long esum[maxn];
long long mesum[maxn];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        bsum[0] = a[0];
        for (int i = 1; i < n; i++) {
            bsum[i] = max(a[i] + bsum[i-1], a[i]);
        }
        esum[n-1] = a[n-1];
        mesum[n-1] = esum[n-1];
        for (int i = n-2; i >= 0; i--) {
            esum[i] = max(a[i] + esum[i+1], a[i]);
            mesum[i] = max(mesum[i+1], esum[i]);
        }
        long long maximum = -10000ll * maxn;
        for (int i = 0; i < n-1; i++) {
            maximum = max(maximum,  bsum[i] + mesum[i+1]);
        }
        printf("%lld\n", maximum);
    }
    return 0;
}