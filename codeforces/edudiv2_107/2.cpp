#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int digits(int num) {
    int cnt = 0;
    while (num) {
        num /= 10; cnt++;
    }
    return cnt;
}
int main() {
    int t; scanf("%d", &t); while (t--) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        int gcd = pow(10, c-1);
        int x = (int)(pow(10, a-1)+0.5) + gcd;
        int y = (int)(pow(10, b-1)+0.5);
        printf("%d %d\n", x, y);
    }
    return 0;
}