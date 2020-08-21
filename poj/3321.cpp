// WA原因：change那个地方忘记设置hasapple为false了
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 100005;
struct v {
    int num;
    int parent;
    bool hasapple;
    int applecnt;
    vector<int> sons;
}vs[maxn];
void change(int i) {
    int cur = i;
    int applechange = vs[i].hasapple? -1: 1;
    vs[i].hasapple = !vs[i].hasapple;
    while (cur != 0) {
        vs[cur].applecnt += applechange;
        cur = vs[cur].parent;
    }
}
int query(int i) {
    return vs[i].applecnt;
}
int init(int cur, int parent) {
    vs[cur].parent = parent;
    vs[cur].num = cur;
    vs[cur].hasapple = true;
    int t = 1;
    for (int i = 0; i < vs[cur].sons.size(); i++) {
        if (vs[cur].sons[i] == parent) continue;
        t += init(vs[cur].sons[i], cur);
    }
    vs[cur].applecnt = t;
    return t;
}
int main() {
    int n;
    scanf("%d", &n);
    memset(vs, 0, sizeof(vs));
    for (int i = 1; i <= n - 1; i++) {
        int father, son;
        scanf("%d%d", &father, &son);
        vs[father].sons.push_back(son);
        vs[son].sons.push_back(father);
    }
    init(1, 0);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        char op; int num;
        cin >> op >> num;
        if (op == 'C') {
            change(num);
        } else {
            printf("%d\n", query(num));
        }
    }
    return 0;
}