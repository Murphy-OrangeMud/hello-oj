#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, x; scanf("%d%d", &n, &x);
        vector<int> ans;
        vector<int> pieces;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int m; scanf("%d", &m); sum+=m;pieces.push_back(m);
        }
        if (sum == x) {
            printf("NO\n");
            continue;
        } else {
            sum = 0;
            for (int i = 0; i < n; i++) {
                if (sum + pieces[i] == x) {
                    sum += pieces[i+1];
                    sum += pieces[i];
                    ans.push_back(pieces[i+1]);
                    ans.push_back(pieces[i]);
                    i++;
                } else {
                    sum += pieces[i];
                    ans.push_back(pieces[i]);
                }
            }
            printf("YES\n");
            for (int i = 0; i < n; i++) {
                if (i) printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}