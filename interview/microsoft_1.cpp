#include<iostream>
using namespace std;    

struct Node {
    int val;
    Node *nxt;
    Node(int _v, Node *_nxt): val(_v), nxt(_nxt) {}
};

Node *reverse(Node *cur) {
    if (cur->nxt->nxt == NULL) {
        Node *tmp = cur->nxt;
        cur->nxt = NULL;
        tmp->nxt = cur;
        return tmp;
    } else {
        Node *tmp = reverse(cur->nxt);
        cur->nxt->nxt = cur;
        cur->nxt = NULL;
        return tmp;
    }
}

Node *func(Node *root) {
    if (root == NULL || root->nxt == NULL) return root;
    Node *tmp = reverse(root);
    return tmp;
}

int main() {
    Node *root = new Node(1,new Node(2, new Node(3, new Node(4,NULL))));
    Node *tmp = reverse(root);
    while (tmp) {
        cout << tmp->val << endl;
        tmp = tmp->nxt;
    }
    return 0;
}