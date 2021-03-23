#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 2e5+5;
char str[maxn];
int cnt[maxn];
int ans[27];
void print(int *a) {
    for (int i = 0; i < 26; i++) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d%d", &n, &m);
        char c[10]; cin.getline(c,10);
        cin.getline(str, n+4);
        memset(cnt,0,sizeof(cnt));
        memset(ans,0,sizeof(ans));
        for (int i =0; i < m;i++) {
            int x; scanf("%d", &x);
            cnt[x]++;
        }
        cnt[n]++;
        for (int i = n; i >0; i--) {
            cnt[i-1] += cnt[i];
        }
        for (int i = 0; i < n; i++) {
            ans[str[i]-'a'] += cnt[i+1];
        }
        print(ans);
    }
    return 0;
}