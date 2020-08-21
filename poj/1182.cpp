#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 50005;
int parent[maxn];
int relation[maxn];
int getroot(int a) {
    if (a != parent[a]) {
        int t = getroot(parent[a]);
        if (relation[a] == 1) {
            relation[a] = relation[parent[a]];
        } else if (relation[a] == 0) {
            if (relation[parent[a]] == 0) {
                relation[a] = 2;
            } else if (relation[parent[a]] == 2) {
                relation[a] = 1;
            } else {
                relation[a] = 0;
            }
        } else if (relation[a] == 2) {
            if (relation[parent[a]] == 2) {
                relation[a] = 0;
            } else if (relation[parent[a]] == 0) {
                relation[a] = 1;
            } else {
                relation[a] = 2;
            }
        }
        parent[a] = t;
    }
    return parent[a];
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int cnt = 0;
    memset(relation, -1, sizeof(relation));
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        relation[i] = 1;
    }
    for (int i = 0; i < k; i++) {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if (x > n || y > n) {
            cnt++;
            continue;
        }
        int px = getroot(x);
        int py = getroot(y);
        if (d == 1) {
            if (px != py) {
                parent[px] = py;
                if (relation[x] == 1) {
                    relation[px] = relation[y];
                } else if (relation[x] == 0) {
                    if (relation[y] == 1) {
                        relation[px] = 2;
                    } else if (relation[y] == 2) {
                        relation[px] = 0;
                    } else {
                        relation[px] = 1;
                    } // correct
                } else {
                    if (relation[y] == 1) {
                        relation[px] = 0;
                    } else if (relation[y] == 2) {
                        relation[px] = 1;
                    } else if (relation[y] == 0) {
                        relation[px] = 2;
                    } // correct
                }
            } else {
                if (relation[y] != relation[x]) cnt++;
            }
        } else { // d == 2
            if (x == y) cnt++;
            else {
                if (px != py) {
                    parent[px] = py;
                    if (relation[x] == 1) {
                        if (relation[y] == 1) {
                            relation[px] = 2;
                        } else if (relation[y] == 2) {
                            relation[px] = 0;
                        } else { 
                            relation[px] = 1;
                        } // correct
                    } else if (relation[x] == 0) {
                        if (relation[y] == 1) {
                            relation[px] = 0;
                        } else if (relation[y] == 2) {
                            relation[px] = 1;
                        } else {
                            relation[px] = 2;
                        } // correct
                    } else {
                        if (relation[y] == 1) {
                            relation[px] = 1;
                        } else if (relation[y] == 2) {
                            relation[px] = 2;
                        } else if (relation[y] == 0) {
                            relation[px] = 0;
                        } // correct
                    }
                } else {
                    if (relation[x] == 1) {
                        if (relation[y] != 0) cnt++;
                    } else if (relation[x] == 2) {
                        if (relation[y] != 1) cnt++;
                    } else {
                        if (relation[y] != 2) cnt++;
                    } // correct
                }
            }
        } // d == 1 || 2
    }
    printf("%d\n", cnt);
    return 0;
}