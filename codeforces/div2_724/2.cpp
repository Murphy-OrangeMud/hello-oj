#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1e7+5;

struct node {
    node *parent;
    int idx;
    node *sons[26];
    node() {
        parent = NULL;
        for (int i = 0; i < 26; i++) {
            sons[i] = NULL;
        }
    }
};

node *root;

void insert(string s) {
    node *current = root;
    for (int i = 0; i < s.length(); i++) {
        if (current->sons[s[i] - 'a'] == NULL) {
            current->sons[s[i] - 'a'] = new node();
            current->sons[s[i] - 'a']->parent = current;
            current->sons[s[i] - 'a']->idx = s[i] - 'a';
        }
        current = current->sons[s[i] - 'a'];
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; string s; cin >> s;
        root = new node();
        for (int i = 0; i < n; i++) {
            insert(s.substr(i, n-i));
        }
        string prefix;
        queue<node *> q;
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            node *cur = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (cur->sons[i] == NULL) {
                    prefix += (i + 'a');
                    while (cur != root) {
                        prefix += (cur->idx + 'a');
                        cur = cur->parent;
                    }
                    for (int i = prefix.length()  - 1; i >= 0; i--) {
                        cout << prefix[i];
                    }
                    cout << endl;
                    flag = true; break;
                } else {
                    q.push(cur->sons[i]);
                }
            }
            if (flag) break;
        }
    }
    return 0;
}