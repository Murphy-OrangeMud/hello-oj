#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        if (n % k == 0) {
            for (int i = 0; i < k; i++) {
                if (i) printf(" ");
                printf("%d", n/k);
            }
            printf("\n");
        }
        else {
            for (int x = 1; x <= n/2; x++) {
                if ((n/2-(k-2)*x/2) < 0) break;
                if ((n/2-(k-2)*x/2)+(n/2-(k-2)*x/2)+(k-2)*x != n) continue;
                if ((x == 1) || ((n/2-(k-2)*x/2)%x == 0) || (x%(n/2-(k-2)*x/2) == 0)) {
                    for (int i = 0; i < k-2; i++){
                        if (i) printf(" ");
                        printf("%d", x);
                    }
                    printf(" %d %d\n", (n/2-(k-2)*x/2), (n/2-(k-2)*x/2));
                    break;
                }
            }
        }
    }
    return 0;
}