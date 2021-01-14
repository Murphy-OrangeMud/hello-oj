#include <cstdio>
using namespace std;
const int maxn = 1e6+10;
int minq[maxn*2][2];
int maxq[maxn*2][2];
int maxnum[maxn];
int minnum[maxn];
int a[maxn];
int n, k;
void findm() {
    int minh = -1, mint = 0, maxh = -1, maxt = 0;
    minq[mint++][0] = a[0]; 
    maxq[maxt++][0] = a[0]; 
    for (int i = 1; i < k; i++) {
        while (mint > minh && minq[--mint][0] > a[i]);
        minq[++mint][0] = a[i];
        minq[mint++][1] = i;
        while (maxt > maxh && maxq[--maxt][0] < a[i]);
        maxq[++maxt][0] = a[i];
        maxq[maxt++][1] = i;
    }
    for (int i = k; i < n; i++) {
        minnum[i-k] = minq[minh+1][0];
        if (minq[minh+1][1] <= i-k) minh++;
        maxnum[i-k] = maxq[maxh+1][0];
        if (maxq[maxh+1][1] <= i-k) maxh++;
        while (mint > minh && minq[--mint][0] > a[i]);
        minq[++mint][0] = a[i];
        minq[mint++][1] = i;
        while (maxt > maxh && maxq[--maxt][0] < a[i]);
        maxq[++maxt][0] = a[i];
        maxq[maxt++][1] = i;
    }
    minnum[n-k] = minq[++minh][0];
    maxnum[n-k] = maxq[++maxh][0];

    for (int i = 0; i <= n-k; i++) {
        if (i) printf(" ");
        printf("%d", minnum[i]);
    }
    printf("\n");
    for (int i = 0; i <= n-k; i++) {
        if (i) printf(" ");
        printf("%d", maxnum[i]);
    }
    printf("\n");
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    findm();
    return 0;
}