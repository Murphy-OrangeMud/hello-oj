// AC: 注意dist[i][i]要设置成0
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 105;
const int inf = 0xffffff;
int dist[maxn][maxn];
int n;
void floyd() {
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            dist[i][j] = inf;
        }
        dist[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int nn;
        cin >> nn;
        for (int j = 1; j <= nn; j++) {
            int a, b;
            cin >> a >> b;
            dist[i][a] = b;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    int minimum = inf, minix = -1;
    for (int i = 1; i <= n; i++) {
        int maximum = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] > maximum) {
                maximum = dist[i][j];
            }
        }
        if (maximum < minimum) {
            minimum = maximum;
            minix = i;
        }
    }
    if (minix == -1) {
        cout << "disjoint" << endl;
    } else {
        cout << minix << " " << minimum << endl;
    }
}
int main() {
    while (cin >> n && n) {
        floyd();
    }
    return 0;
}