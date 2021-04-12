#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
    int n, q; scanf("%d%d", &n, &q);
    int a[55]; 
    for (int i = 0; i < 55; i++) {
        a[i] = n+1;
    }
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        a[x] = min(a[x], i);
    }
    for (int i = 1; i <= q; i++) {
        int t; scanf("%d", &t);
        if (i > 1) printf(" ");
        printf("%d", a[t]);
        for (int i = 0; i < 55; i++) {
            if (a[i] < a[t]) a[i]++;
        }
        a[t] = 1;
    }
    return 0;
}