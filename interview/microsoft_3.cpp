/*
input - binary search tree

 16
/ \
14 25
/ \ \
8 15 29
/
27

output
27
29 15 8
25 14
16
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *l;
    Node *r;
    Node(int _val, Node* _l, Node *_r): val(_val), l(_l), r(_r) {}
    Node () {}
};

struct state {
    int depth;
    Node *val;
    state(int _d,Node * _v): depth(_d),val(_v) {}
    state() {}
};

void func(Node *root) {
    vector<vector<Node*>> v;
    v.push_back(state(0, root));
    int t = -1;
    while (t < v.size()) {
        t++;
        state cur = v[t];
        if (cur.val->l) {
            v.push_back(state(v[t].depth+1, cur->l->val));
        }
        if (cur.val->r) {
            v.push_back(state(v[t].depth+1, cur->r->val));
        }
    }
    for (int i=v.size()-1; i>=0;i--) {
        if (i != v.size() - 1 && v[i].depth != v[i+1].depth) {
            cout << endl;
        } else if (i != v.size() - 1){
            cout << " ";
        }
        cout << v[i].val;
    }
    cout << endl;
}