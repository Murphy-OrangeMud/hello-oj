#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        int maximum = 0; int minimum = 0;
        vector<int> a;
        map<int,int> m;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x); m[x]++; a.push_back(x);
            if (maximum < x) maximum = x;
        }
        sort(a.begin(),a.end());
        if (a[0] > 0) minimum = 0;
        else {
            for (int i = 0; i < n; i++) {
                if (i == n-1 || a[i] < a[i+1]-1) {minimum = a[i]+1; break;}
            }
        }
        if (k) {
            int toadd = (minimum + maximum) / 2 + (minimum + maximum) % 2;
            if (toadd > maximum) {
                printf("%ld\n", k+m.size());
            }
            else {
                m[toadd]++;
                printf("%ld\n", m.size());
            }
        } else {
            printf("%ld\n", m.size());
        }
    }
    return 0;
}