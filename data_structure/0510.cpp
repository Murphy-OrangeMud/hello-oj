#include <iostream>
#include <vector>
using namespace std;
struct node {
    node *l, *r;
    int val;
    node(int _val = -1, node *_l = NULL, node *_r = NULL): val(_val), l(_l), r(_r) {}
};
vector<int> mid;
vector<int> back;
node *build(int midl, int midr, int backl, int backr) {
    if (midl > midr) {
        return NULL;
    }
    if (midl == midr) {
        return new node(mid[midl]);
    }
    int backroot = back[backr];
    int mididx;
    for (int i = midl; i <= midr; i++) {
        if (mid[i] == backroot) {
            mididx = i;
            break;
        }
    }
    node *l = build(midl, mididx - 1, backl, backl + mididx - midl - 1);
    node *r = build(mididx + 1, midr, backl + mididx - midl, backr - 1);
    return new node(backroot, l, r);
}
void del(node *cur) {
    if (cur->l) del(cur->l);
    if (cur->r) del(cur->r);
    delete cur;
}
void prevtraverse(node *cur) {
    printf(" %d", cur->val);
    if (cur->l) prevtraverse(cur->l);
    if (cur->r) prevtraverse(cur->r);
}
int main() {
    int v;
    char c;
    while ((c = cin.peek()) != '\n') {
        scanf("%d", &v);
        mid.push_back(v);
    }
    char n = getchar();
    c = ' ';
    while ((c = cin.peek()) != '\n') {
        scanf("%d", &v);
        back.push_back(v);
    }
    node *cur = build(0, mid.size() - 1, 0, back.size() - 1);
    printf("%d", cur->val);
    prevtraverse(cur->l);
    prevtraverse(cur->r);
    printf("\n");
    del(cur);
    return 0;
}