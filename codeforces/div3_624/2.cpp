#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

struct ai {
    int idx;
    int val;
    ai(int _idx, int _val): idx(_idx), val(_val) {}
    bool operator < (const ai & other) const {
        if (val < other.val) return true;
        else if (val == other.val) {
            return idx < other.idx;
        }
        return false;
    }
};

const int maxn = 105;
int p[maxn];
int pp[maxn][2];

int main() {
    int t; scanf("%d",&t);
    while (t--) {
        int n, m; scanf("%d%d", &n, &m);
        vector<ai> a;
        memset(p,0,sizeof(p));
        memset(pp,0,sizeof(pp));
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            a.push_back(ai(i+1,x));
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &p[i]);
        }
        sort(p,p+m);
        for (int i = 1; i <= n; i++) {
            pp[i][0] = pp[i][1] = i;
        }
        for (int i = 0; i < m-1; i++) {
            if (p[i] == p[i+1]-1) {
                pp[p[i+1]][0] = pp[p[i]][0];
            } else {
                pp[p[i]+1][0] = pp[p[i]][0];
            }
        }
        pp[p[m-1]+1][0] = pp[p[m-1]][0];
        pp[p[m-1]][1]++;
        for (int i =m-1;i > 0;i--) {
            if (p[i] == p[i-1]+1) {
                pp[p[i-1]][1] = pp[p[i]][1]; 
            } else {
                pp[p[i-1]][1]++;
            }
        }
        bool flag = true;
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++) {
            if (i+1 >= pp[a[i].idx][0] && i+1 <= pp[a[i].idx][1]) continue;
            flag = false; break;
        }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}