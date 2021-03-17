#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--){
        int n, k;
        scanf("%d%d", &n, &k);
        if (n % 3 == 0) {
            printf("%d %d %d\n", n/3, n/3, n/3);
        }
        else {
            if (n % 2 == 0) {
                for (int x = 1; x <= n/4; x++) {
                    if ((n/2-x)%(x*2) == 0 || (2*x)%(n/2-x) == 0) {
                        printf("%d %d %d\n", 2*x, n/2-x, n/2-x);
                        break;
                    }
                }
            }
            else {
                printf("%d %d %d\n", 1, n/2, n/2);
            }
        }
    }
    return 0;
}