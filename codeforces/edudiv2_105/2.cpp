#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, f[4];
        scanf("%d%d%d%d%d", &n, &f[0], &f[1], &f[2], &f[3]);
        if (f[0]<n-1 && f[1]<n-1 && f[2]<n-1 && f[3]<n-1) printf("YES\n");
        else {
            bool flag = true;
            for (int i = 0; i < 4; i++) {
                if (f[i] == n) {
                    if (f[(i+3)%4] < 1 || f[(i+1)%4] < 1) {
                        flag = false;
                        break;
                    }
                    if (f[(i+2)%4] == n-1) {
                        if (f[(i+3)%4] < 2 && f[(i+1)%4] < 2) {
                            flag = false;
                            break;
                        }
                    }
                    else if (f[(i+2)%4] == n) {
                        if (f[(i+3)%4] < 2 || f[(i+1)%4] < 2) {
                            flag = false;
                            break;
                        }
                    }
                }
                else if (f[i] == n-1) {
                    if (f[(i+3)%4] < 1 && f[(i+1)%4] < 1) {
                        flag = false;
                        break;
                    }
                    if (f[(i+2)%4] == n-1) {
                        if (f[(i+3)%4] + f[(i+1)%4] < 2) {
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if (flag) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}