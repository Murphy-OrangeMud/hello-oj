#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 4005;
int n;
long long a[maxn],b[maxn],c[maxn],d[maxn];
int aplusb[maxn*maxn];
void solve() {
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", a[i], b[i], c[i], d[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aplusb[a[i]+b[j]]++;
        }
    }
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt += aplusb[-c[i]-d[j]];
        }
    }
    cout << cnt << endl;
}
int main() {
    solve();
    return 0;
}