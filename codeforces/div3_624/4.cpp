#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        int ans = 1e9;
        int a_, b_, c_;
        for (int aa = 1; aa <= 2*a; aa++) {
            for (int bb = aa; bb <= 2*b; bb += aa) {
                for (int i = 0; i < 2; i++) {
                    int cc = c/bb*bb + i*bb;
                    if (ans > abs(aa-a)+abs(bb-b)+abs(cc-c)) {
                        ans = abs(aa-a)+abs(bb-b)+abs(cc-c);
                        a_ = aa; b_ = bb; c_ = cc;
                    }
                }
            }
        }
        printf("%d\n%d %d %d\n", ans, a_, b_, c_);
    }
    return 0;
}