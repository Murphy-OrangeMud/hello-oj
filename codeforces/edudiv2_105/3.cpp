#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    int a[2*(int)1e5+5];
    int b[2*(int)1e5+5];
    while (t--) {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int n,m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        int aidx = 0;
        int bidx = 0;
        int dp[2*(int)1e5+5][2];
        memset(dp,0,sizeof(dp));
        for (; b[bidx] < 0 && bidx < m; ) {
            if (aidx >= m || a[aidx] > b[bidx]) {
                dp[bidx][1] = aidx-1;
                dp[bidx][0] = (bidx == 0? 0: dp[bidx-1][0]);
                bidx++;
            }
            else if (a[aidx] == b[bidx]) {
                dp[bidx][0] = (bidx == 0? 0: dp[bidx-1][0])+1;
                dp[bidx][1] = aidx-1;
                aidx++; bidx++;
            }
            else aidx++;
        }
        while(a[aidx]<0 && aidx < m) aidx++;
        int bounda = aidx;
        int boundb = bidx;
        aidx = n-1;
        bidx = m-1;
        for (; bidx >= 0 && b[bidx] > 0; ) {
            if (aidx < 0 || a[aidx] < b[bidx]) {
                dp[bidx][1] = aidx+1;
                dp[bidx][0] = (bidx == m-1? 0: dp[bidx+1][0]);
                bidx--;
            }
            else if (a[aidx] == b[bidx]) {
                dp[bidx][0] = (bidx == m-1? 0: dp[bidx+1][0])+1;
                dp[bidx][1] = aidx+1;
                aidx--; bidx--;
            }
            else aidx--;
        }
        int dpp[2*(int)1e5+5];
        memset(dpp,0,sizeof(dpp));
        if (boundb < m) {
            dpp[boundb] = 1;
            for (int i = boundb+1; i < m; i++) {
                if (b[i-1] == b[i]-1) {
                    dpp[i] = dpp[i-1]+1;
                }
                else {
                    dpp[i] = 1;
                }
            }
        }
        if (boundb > 0) {
            dpp[boundb-1] = 1;
            for (int i = boundb-2; i >= 0; i--) {
                if (b[i+1] == b[i]+1) {
                    dpp[i] = dpp[i+1]+1;
                }
                else {
                    dpp[i] = 1;
                }
            }
        }
        int box = 0;
        int mbox = 0;
        for (int i = 0; b[i] < 0 && i < m; i++) {
            if (dp[i][1] + 1 < m && a[dp[i][1]+1] == b[i]) {
                mbox = max(mbox, min(dpp[i], (bounda-1-dp[i][1]))+dp[i][0]-1);
            }
            else {
                mbox = max(mbox, min(dpp[i], (bounda-1-dp[i][1]))+dp[i][0]);
            }
        }
        box += mbox;
        mbox = 0;
        for (int i = m-1; b[i] > 0 && i >= 0; i--) {
            if (dp[i][1] - 1 >= 0 && a[dp[i][1]-1] == b[i]) {
                mbox = max(mbox, min(dpp[i], dp[i][1] - bounda)+dp[i][0]-1);
            }
            else {
                mbox = max(mbox, min(dpp[i], dp[i][1] - bounda)+dp[i][0]);
            }
        }
        box += mbox;
        printf("anas:%d\n", box);
    }
    return 0;
}