//TLE:把cin换成scanf……
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 50005;
int a[maxn];
struct node {
    int l, r;
    int num;
    int maximum;
    int minimum;
    node () {}
    node (int _l, int _r, int _max = 0, int _min = 0xffffff): l(_l), r(_r), maximum(_max), minimum(_min) {}
}tree[maxn * 5];
void init(int i, int l, int r) {
    tree[i] = node(l, r);
    if (l == r) {
        tree[i].maximum = a[l];
        tree[i].minimum = a[r];
        return;
    }
    int mid = (l + r) / 2;
    init(2*i+1, l, mid);
    init(2*i+2, mid+1, r);
    tree[i].maximum = max(tree[2*i+1].maximum, tree[2*i+2].maximum);
    tree[i].minimum = min(tree[2*i+1].minimum, tree[2*i+2].minimum);
}
void insert(int index, int value, int treeidx) {
    tree[treeidx].maximum = max(tree[treeidx].maximum, value);
    tree[treeidx].minimum = min(tree[treeidx].minimum, value);
    if (tree[treeidx].l == tree[treeidx].r) {
        return;
    }
    int mid = (tree[treeidx].l + tree[treeidx].r) / 2;
    if (index <= mid) insert(index, value, 2*treeidx+1);
    else insert(index, value, 2*treeidx+2);
}
int curmax, curmin;
int maxquery(int ql, int qr, int curidx) {
    int mid = (tree[curidx].l + tree[curidx].r) / 2;
    if (ql <= tree[curidx].l && qr >= tree[curidx].r) {
        return tree[curidx].maximum;
    }
    if (qr <= mid) {
        return maxquery(ql, qr, 2*curidx + 1);
    } else if (ql > mid) {
        return maxquery(ql, qr, 2*curidx + 2);
    } else {
        return max(maxquery(ql, mid, 2*curidx+1), maxquery(mid+1, qr, 2*curidx+2));
    }
}
int minquery(int ql, int qr, int curidx) {
    int mid = (tree[curidx].l + tree[curidx].r) / 2;
    if ((ql <= tree[curidx].l && qr >= tree[curidx].r)) {
        return tree[curidx].minimum;
    }
    if (qr <= mid) {
        return minquery(ql, qr, 2*curidx + 1);
    } else if (ql > mid) {
        return minquery(ql, qr, 2*curidx + 2);
    } else {
        return min(minquery(ql, mid, 2*curidx+1), minquery(mid+1, qr, 2*curidx+2));
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    init(0, 0, n-1);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        curmax = 0xffffff;
        curmin = -0xffffff;
        int maxv = 0, minv = 0xffffff;
        maxv = maxquery(l-1, r-1, 0);
        minv = minquery(l-1, r-1, 0);
        printf("%d\n", maxv - minv);
    }
    return 0;
}
