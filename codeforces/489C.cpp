#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int m, s; cin >> m >> s;
    if ((m > 1 && s == 0) || s > 9 * m) cout << "-1 -1\n"; 
    else {
        int tmps = s;
        int maxnum[105];
        memset(maxnum, 0, sizeof(maxnum));
        int minnum[105];
        memset(minnum, 0, sizeof(minnum));
        for (int i = m; i > 0; i--) {
            int cnt = min(9, s);
            maxnum[m-i] = cnt;
            s -= cnt;
        }
        s = tmps;
        int cnt = (m > 1? max(1, maxnum[m-1]): maxnum[m-1]);
        minnum[0] = cnt;
        s -= cnt;
        for (int i = m-1; i > 0; i--) {
            int cnt = min(9, s);
            minnum[i] = cnt;
            s -= cnt;
        }
        for (int i = 0; i < m; i++) {
            cout << minnum[i];
        }
        cout << " ";
        for (int i = 0; i < m; i++) {
            cout << maxnum[i];
        }
        cout << endl;
    }
    return 0;
}