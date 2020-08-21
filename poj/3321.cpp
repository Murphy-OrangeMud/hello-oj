#include <iostream>
#include <vector>
#include <algorithm>
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
    int t = 1;
    for (int i = 0; i < vs[cur].sons.size(); i++) {
        if (vs[cur].sons[i] == parent) continue;
        t += init(vs[cur].sons[i], cur);
    }
    vs[cur].num = cur;
    vs[cur].hasapple = true;
    vs[cur].applecnt = t;
    return t;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int father, son;
        cin >> father >> son;
        vs[father].sons.push_back(son);
        vs[son].sons.push_back(father);
    }
    init(1, 0);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        char op; int num;
        cin >> op >> num;
        if (op == 'C') {
            change(num);
        } else {
            cout << query(num) << endl;
        }
    }
    return 0;
}