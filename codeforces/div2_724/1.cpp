#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (b == 0) return a;
    else if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n;  scanf("%d",  &n);
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d",  &x); a.push_back(x);
        }
        sort(a.begin(), a.end());
        if (a[0] < 0) {cout << "NO\n";}
        else {
            printf("YES\n101\n");
            for (int i = 0; i < 101; i++) {
                if (i) printf(" ");
                printf("%d", i);
            }
            printf("\n");
        }
    }
    return 0;
}