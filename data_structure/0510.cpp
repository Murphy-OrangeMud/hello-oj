#include <iostream>
#include <vector>
using namespace std;
struct node {
    int val;
    node *l, *r;
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
void prevtraverse(node *cur) {
    cout << " " << cur->val;
    if (cur->l) prevtraverse(cur->l);
    if (cur->r) prevtraverse(cur->r);
}
int main() {
    int v;
    char c;
    while ((c = cin.peek()) != '\n') {
        cin >> v;
        mid.push_back(v);
    }
    char n = getchar();
    c = ' ';
    while ((c = cin.peek()) != '\n') {
        cin >> v;
        back.push_back(v);
    }
    node *cur = build(0, mid.size() - 1, 0, back.size() - 1);
    cout << cur->val;
    prevtraverse(cur->l);
    prevtraverse(cur->r);
    cout << endl;
    return 0;
}