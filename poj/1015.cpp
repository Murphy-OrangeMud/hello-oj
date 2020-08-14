#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 205;
const int maxm = 25;
int sumdp[maxn][maxm];
int minusdp[maxn][maxm];
int pathdp[maxn][maxm][maxn];
int d[maxn];
int p[maxn];
int n, m;
int main() {
    int kase = 0;
    while (cin >> n && n) {
        cin >> m;
        memset(sumdp, 0, sizeof(sumdp));
        memset(minusdp, 1, sizeof(minusdp));
        memset(pathdp, 0, sizeof(pathdp));
        memset(d, 0, sizeof(d));
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= n; i++) {
            cin >> p[i] >> d[i];
        }
        minusdp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            minusdp[i][0] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(m,i); j++) {
                for (int k = 0; k < i; k++) {
                    if (abs(minusdp[k][j-1] + d[i] - p[i]) < abs(minusdp[i][j])) {
                        minusdp[i][j] = minusdp[k][j-1] + d[i] - p[i];
                        sumdp[i][j] = sumdp[k][j-1] + d[i] + p[i];
                        memcpy(pathdp[i][j], pathdp[k][j-1], sizeof(pathdp[k][j-1]));
                        pathdp[i][j][i] = 1;
                    } else if (abs(minusdp[k][j-1] + d[i] - p[i]) == abs(minusdp[i][j])) {
                        if (sumdp[i][j] < sumdp[k][j-1] + d[i] + p[i]) {
                            sumdp[i][j] = sumdp[k][j-1] + d[i] + p[i];
                            memcpy(pathdp[i][j], pathdp[k][j-1], sizeof(pathdp[k][j-1]));
                            pathdp[i][j][i] = 1;
                        }
                    }
                }
            }
        }
        int ans[maxn];
        memset(ans, 0, sizeof(ans));
        int maxsum = 0;
        int mindiff = 0xffffff;
        int i0, j0;
        for (int i = 1; i <= n; i++) {
            if (mindiff > abs(minusdp[i][m]) || (mindiff == abs(minusdp[i][m]) && maxsum < sumdp[i][m])) {
                i0 = i;
                mindiff = abs(minusdp[i][m]);
                maxsum = sumdp[i][m];
                memcpy(ans, pathdp[i][m], sizeof(pathdp[i][m]));
            }
        }
        int dsum = 0, psum = 0;
        for (int i = 1; i <= n; i++) {
            if (ans[i] == 0) continue;
            dsum += d[i];
            psum += p[i];
        }
        cout << "Jury #" << ++kase << endl;
        cout << "Best jury has value " << psum << " for prosecution and value " << dsum << " for defence:" << endl;
        for (int i = 1; i <= n; i++) {
            if (ans[i] == 0) continue;
            cout << " " << i;
        }
        cout << endl << endl;
    }
    return 0;
}