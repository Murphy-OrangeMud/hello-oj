#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 2e5+5;
char str[maxn];

int solve() {
    int n, k;
    scanf("%d%d",&n, &k);
    char c[10];
    cin.getline(c, 10);
    cin.getline(str, n+1);
    int cnt = 0;
    for (int i = 0; i < n/2; i++) {
        if (str[i] == str[n-i-1]) cnt++;
    }
    return (abs(n/2-k-cnt));
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        printf("Case #%d: %d\n", i+1, solve());
    }
    return 0;
}