#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int maxlen = 1005;
int dp[maxlen];
char s[maxlen];
int palindrome[maxlen][maxlen];
void init() {
    memset(palindrome, 0, sizeof(palindrome));
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= i; j++) {
            if (i + j >= len) break;
            if (s[i-j] != s[i+j]) break;
            palindrome[i-j][i+j] = 1;
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= i; j++) {
            if (i + j + 1 >= len) break;
            if (s[i-j] != s[i+j+1]) break;
            palindrome[i-j][i+j+1] = 1;
        }
    }
}
void f() {
    memset(dp, 1, sizeof(dp));
    int len = strlen(s);
    init();
    dp[0] = 0;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            if (!palindrome[j][i-1]) continue;
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    printf("%d\n", dp[len]);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        f();
    }
    return 0;
}