#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool solve(char *s, int k) {
    int len = strlen(s);
    int i;
    for (i = 0; i <= len/2; i++) {
        if (i >= len-1-i || s[i] != s[len-1-i]) break;
    }
    if (i > len-1-i && k >= i) return false;
    if (k > i) return false;
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    char s[105];
    char c[10];
    while (t--) {
        int x, k;
        scanf("%d%d", &x, &k);
        cin.getline(c, 10);
        cin.getline(s, 101);
        if (solve(s, k)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}