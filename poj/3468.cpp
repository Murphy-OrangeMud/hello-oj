// TLE: 用scanf替代cin。不要用vector（题目会卡）
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100005;
struct node {
    long long l, r;
    long long sum;
    long long delta;
    //vector<long long> a;
    node(){}
    node(long long _l, long long _r, long long _d = 0, long long _sum = 0): l(_l), r(_r), delta(_d), sum(_sum) {}
}tree[5*maxn];
void init(int i, int l, int r) {
    tree[i] = node(l, r);
    if (l == r) return;
    int mid = (l + r) / 2;
    init(2*i+1, l, mid);
    init(2*i+2, mid + 1, r);
}
void insert(int i, int idx, long long val) {
    //tree[i].a.push_back(val);
    tree[i].sum += val;
    if (tree[i].l == tree[i].r) return;
    int mid = (tree[i].l + tree[i].r) / 2;
    if (idx <= mid) {
        insert(2*i+1, idx, val);
    } else {
        insert(2*i+2, idx, val);
    }
}
void update(int ul, int ur, long long delta, int i) {
    if (ul <= tree[i].l && ur >= tree[i].r) {
        tree[i].delta += delta;
        //tree[i].sum += delta * (tree[i].r - tree[i].l + 1);
        return;
    }
    int mid = (tree[i].l + tree[i].r) / 2;
    tree[i].sum += (ur - ul + 1) * delta;
    if (ur <= mid) {
        update(ul, ur, delta, 2*i+1);
    } else if (ul > mid) {
        update(ul, ur, delta, 2*i+2);
    } else {
        update(ul, mid, delta, 2*i+1);
        update(mid+1, ur, delta, 2*i+2);
    }
}
long long query(int ql, int qr, int i) {
    if (ql <= tree[i].l && qr >= tree[i].r) {
        if (tree[i].delta != 0) {
            return tree[i].sum + tree[i].delta * (qr - ql + 1);
        } else {
            return tree[i].sum;
        }
    }
    else {
        tree[2*i+1].delta += tree[i].delta;
        tree[2*i+2].delta += tree[i].delta;
        tree[i].sum += tree[i].delta * (tree[i].r - tree[i].l + 1);
        tree[i].delta = 0;
        int mid = (tree[i].l + tree[i].r) / 2;
        if (qr <= mid) {
            return query(ql, qr, 2*i+1);
        } else if (ql > mid) {
            return query(ql, qr, 2*i+2);
        } else {
            return query(ql, mid, 2*i+1) + query(mid+1, qr, 2*i+2);
        }
    }
}
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    init(0, 0, n-1);
    for (int i = 0; i < n; i++) {
        long long v;
        scanf("%lld", &v);
        insert(0, i, v);
    }
    for (int i = 0; i < q; i++) {
        char op;
        //op = getchar();
        scanf("\n%c ", &op);
        //cout << op << endl;
        if (op == 'C') {
            int a, b;
            long long c;
            scanf("%d%d%lld", &a, &b, &c);
            update(a-1, b-1, c, 0);
        } else {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%lld\n", query(a-1, b-1, 0));
        }
    }
    return 0;
}