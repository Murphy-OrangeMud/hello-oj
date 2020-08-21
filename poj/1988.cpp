#include <iostream>
using namespace std;
const int maxn = 30005;
int parent[maxn];
int up[maxn];
int down[maxn];
int getroot(int a) {
    if (parent[a] != a) {
        up[a] = up[parent[a]] - down[a];
        int t = getroot(parent[a]);
        down[a] += down[parent[a]];
        parent[a] = t;
    }
    return parent[a];
}
void merge(int a, int b) {
    int pa = getroot(a);
    int pb = getroot(b);
    if (pa != pb) {
        parent[pb] = pa;
        down[pb] += up[pa];
        up[pa] += up[pb];
    }
}
int query(int x) {
    int p = getroot(x);
    return down[x];
}
int main() {
    int p;
    cin >> p;
    for (int i = 0; i < maxn; i++) {
        parent[i] = i;
        up[i] = 1;
    }
    for (int i = 0; i < p; i++) {
        char op;
        cin >> op;
        if (op == 'M') {
            int x, y;
            cin >> x >> y;
            merge(y, x);
        }
        if (op == 'C') {
            int x;
            cin >> x;
            cout << query(x) << endl;
        }
    }
    return 0;
}

