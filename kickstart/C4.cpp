// WA: 没有开long long
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 2 * 1e5 + 5;
struct node {
    int l, r;
    long long presum;
    long long aftsum;
    node() {}
    node(int _l, int _r, int _presum = 0, int _aftsum = 0): l(_l), r(_r), presum(_presum), aftsum(_aftsum) {};
}tree[maxn * 4 + 1];
void init(int i, int l, int r) {
    tree[i] = node(l, r);
    if (l == r) {
        scanf("%lld", &tree[i].presum);
        tree[i].aftsum = tree[i].presum * (l * pow(-1, l-1));
        tree[i].presum *= pow(-1, l-1);
        //cout << l << " " << r << " " << tree[i].presum << " " << tree[i].aftsum << endl;
        return;
    }
    int mid = (l + r) / 2;
    init(2*i+1, l, mid);
    init(2*i+2, mid+1, r);
    tree[i].presum += (tree[2*i+1].presum + tree[2*i+2].presum);
    tree[i].aftsum += (tree[2*i+1].aftsum + tree[2*i+2].aftsum);
    //cout << l << " " << r << " " << tree[i].presum << " " << tree[i].aftsum << endl;
}
void update(int x, int v, int cur) {
    int mid = (tree[cur].l + tree[cur].r) / 2;
    if (tree[cur].l == tree[cur].r) {
        tree[cur].presum = v * pow(-1, x-1);
        tree[cur].aftsum = v * pow(-1, x-1) * x;
        return;
    }
    if (x <= mid) {
        tree[cur].presum -= tree[2*cur+1].presum;
        tree[cur].aftsum -= tree[2*cur+1].aftsum;
        update(x, v, 2*cur+1);
        tree[cur].presum += tree[2*cur+1].presum;
        tree[cur].aftsum += tree[2*cur+1].aftsum;
    } else {
        tree[cur].presum -= tree[2*cur+2].presum;
        tree[cur].aftsum -= tree[2*cur+2].aftsum;
        update(x, v, 2*cur+2);
        tree[cur].presum += tree[2*cur+2].presum;
        tree[cur].aftsum += tree[2*cur+2].aftsum;
    }
}
long long aftquery(int ql, int qr, int cur) {
    if (tree[cur].l == ql && tree[cur].r == qr) {
        return tree[cur].aftsum;
    }
    int mid = (tree[cur].l + tree[cur].r) / 2;
    if (qr <= mid) {
        return aftquery(ql, qr, 2*cur+1);
    }
    else if (ql > mid) {
        return aftquery(ql, qr, 2*cur+2);
    }
    else {
        return aftquery(ql, mid, 2*cur+1) + aftquery(mid+1, qr, 2*cur+2);
    }
}
long long prequery(int ql, int qr, int cur) {
    if (tree[cur].l == ql && tree[cur].r == qr) {
        return tree[cur].presum;
    }
    int mid = (tree[cur].l + tree[cur].r) / 2;
    if (qr <= mid) {
        return prequery(ql, qr, 2*cur+1);
    }
    else if (ql > mid) {
        return prequery(ql, qr, 2*cur+2);
    }
    else {
        return prequery(ql, mid, 2*cur+1) + prequery(mid+1, qr, 2*cur+2);
    }
}
void solve() {
    memset(tree, 0, sizeof(tree));
    int n, m;
    cin >> n >> m;
    init(0, 1, n);
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        char op;
        cin >> op;
        if (op == 'U') {
            int x, v;
            cin >> x >> v;
            update(x, v, 0);
        }
        if (op == 'Q') {
            int ql, qr;
            cin >> ql >> qr;
            long long curans = aftquery(ql, qr, 0);
            cout << curans << endl;
            //cout << prequery(ql, qr, 0) << endl;
            curans -= (prequery(ql, qr, 0) * (ql - 1));
            curans *= pow(-1, ql - 1);
            cout << curans << endl;
            ans += curans;
        }
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}
