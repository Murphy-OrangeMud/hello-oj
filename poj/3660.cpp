#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 105;
const int inf = 0xffffff;
int dist[maxn][maxn];
int undefined[maxn];
int m, n;
void floyd() {
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < maxn; j++) {
            dist[i][j] = inf;
        }
        dist[i][i] = 0;
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == inf && dist[j][i] == inf) {
                undefined[i] = 1;
                undefined[j] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (undefined[i] == 1) ++cnt;
    }
    cout << n - cnt << endl;
}
int main() {
    floyd();
}