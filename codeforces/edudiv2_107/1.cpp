#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t; scanf("%d", &t); while (t--) {
        int n; scanf("%d", &n); int cnt = 0;
        while (n--) {
            int x; scanf("%d", &x); if (x == 1 || x == 3) ++cnt;
        }
        printf("%d\n", cnt);
    }
    return 0;
}