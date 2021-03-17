#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        map<int,int> mm;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x); mm[x%m]++; 
        }
        int tot = (mm[0]? 1:0);
        for (int i = 1; i <= m/2; i++) {
            if (mm[i] == 0 && mm[m-i] == 0) continue;
            int diff = abs(mm[i]-mm[m-i]);
            tot += max(1, diff);
        }
        printf("%d\n", tot);
    }
    return 0;
}