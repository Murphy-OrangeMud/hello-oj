#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int t; scanf("%d", &t); while (t--) {
        int n; scanf("%d", &n);
        vector<int> odd; vector<int> even;
        while (n--) {
            int x; scanf("%d", &x); if (x%2) odd.push_back(x); else even.push_back(x);
        }
        for (int i = 0; i < odd.size(); i++) {if (i) printf(" "); printf("%d", odd[i]);}
        for (int i = 0; i < even.size(); i++) printf(" %d", even[i]);
        printf("\n");
    }
    return 0;
}