#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        map<int,int> m;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            for (int j = 2; j*j <= x; j++) {
                while (x%(j*j) == 0) x /= (j*j);
            }
            if (m[x]) {
                m.clear();
                ans++;
                m[x]++;
            }
            else m[x]++;
        }
        if (!m.empty()) ans++;
        printf("%d\n", ans);
    }
    return 0;
}