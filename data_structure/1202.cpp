// WA: 没找到原因
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 35;
int n;
int A[maxn][maxn];
int b[maxn];
int op[maxn];
int ed[maxn];
// swap 2 lines
void SWAP(int i, int j) {
    for (int k = 1; k <= n; k++) {
        int t = A[i][k];
        A[i][k] = A[j][k];
        A[j][k] = t;
    }
    int t = b[i];
    b[i] = b[j];
    b[j] = t;
}
void XOR(int i, int j) {
    for (int k = 1; k <= n; k++) {
        A[j][k] ^= A[i][k];
    }
    b[j] ^= b[i];
}
void solve() {
    for (int i = 1; i <= n; i++) {
        if (A[i][i] != 1) {
            for (int j = i + 1; j <= n; j++) {
                if (A[j][i] == 1) {
                    SWAP(i, j);
                    break;
                }
            }
        }
        if (A[i][i]) {
            for (int j = 1; j <= n; j++) {
                if (j == i) continue;
                if (A[j][i] == 1) {
                    XOR(i, j);
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 1; j <= n; j++) {
            if (A[i][j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            if (b[i]) {
                cout << "Oh,it's impossible~!!" << endl;
                return;
            }
            else {
                ++cnt;
            }
        }
    }
    cout << pow(2, cnt) << endl;
    return;
}
int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        memset(A, 0, sizeof(A));
        memset(b, 0, sizeof(b));
        memset(op, 0, sizeof(op));
        memset(ed, 0, sizeof(ed));
        cin >> n;
        for (int j = 1; j <= n; j++) {
            cin >> op[j];
        }
        for (int j = 1; j <= n; j++) {
            cin >> ed[j];
            b[j] = op[j] ^ ed[j];
        }
        int x, y;
        for (int j = 1; j <= n; j++) {
            A[j][j] = 1;
        }
        while (cin >> x >> y && x && y) {
            A[y][x] = 1;
        }
        solve();
    }
    return 0;
}