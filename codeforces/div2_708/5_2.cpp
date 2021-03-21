#include <iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

const int maxa = 1e9+5;
const int maxn = 2*1e5+5;
const int maxk = 25;
int a[maxn];
int cnt[maxa];
int mleft[maxn][maxk];
int dp[maxn][maxk];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        memset(a,0,sizeof(a));
        memset(cnt,0,sizeof(cnt));
        memset(mleft,0,sizeof(mleft));
        memset(dp, 1, sizeof(dp));
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            for (int j = 2; j*j <= x; j++) {
                while (x%(j*j) == 0) x /= (j*j);
            }
            a[i] = x;
        }
        for (int j = 0; j <= k; j++) {
            int l = n, now = 0;
            for (int i = n-1; i>= 0; i--) {
                while (l-1>= 0 && now+(cnt[a[l-1]]>0)<=j) {
                    l--;
                    now += (cnt[a[l]] > 0); // 把前面的那个改了，而不是这个
                    cnt[a[l]]++;
                }
                mleft[i][j] = l;
                if (cnt[a[i]]>1) now--; // a[i]改过
                cnt[a[i]]--;
            }
        }
        memset(dp[0], 0, sizeof(dp[0]));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j > 0) dp[i][j] = dp[i][j-1];
                for (int l = 0; l<= j; l++) {
                    dp[i][j] = min(dp[i][j], dp[mleft[i-1][l]][j-l]+1);
                }
            }
        }
        int ans = 1e9;
        for (int i = 0; i <= k; i++) {
            ans = min(ans, dp[n][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}