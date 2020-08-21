#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 30005;
int parent[maxn];
int getroot(int a) {
    if (a != parent[a]) {
        parent[a] = getroot(parent[a]);
    }
    return parent[a];
}
int main() {
    int n, m;
    while (cin >> n && n) {
        memset(parent, -1, sizeof(parent));
        for (int i = 0; i < maxn; i++) {
            parent[i] = i;
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            int stu1;
            cin >> stu1;
            int p = getroot(stu1);
            for (int j = 0; j < num - 1; j++) {
                int x;
                cin >> x;
                int px = getroot(x);
                if (px != p) {
                    parent[px] = p;
                }
            }
        }
        int cnt = 1;
        int px = getroot(0);
        for (int i = 1; i < n; i++) {
            if (getroot(i) == px) {
                ++cnt;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}