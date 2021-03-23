#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 2e5+5;
const int maxm = 2e5+5;
int letters[maxn][27];
int ans[27];

void add(int *a1, int *a2) {
    for (int i = 0; i < 26; i++) {
        a1[i] += a2[i];
    }
}
void print(int *a) {
    for (int i = 0; i < 26; i++) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d%d",&n, &m);
        char c = getchar(); c = getchar();
        memset(letters, 0, sizeof(letters));
        memset(ans, 0, sizeof(ans));
        int i = 1;
        while (c != '\n') {
            add(letters[i], letters[i-1]);
            letters[i][c - 'a']++; i++;
            c = getchar();
        }
        for (int j = 0; j < m; j++) {
            int x; scanf("%d", &x);
            add(ans, letters[x]);
        }
        add(ans, letters[i-1]);
        print(ans);
    }
    return 0;
}