#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 250 * 1005;
struct node {
    int child[27];
    int badnode;
    int prev;
}tree[maxn];
int cnt = 1;
int n = 0;
//to be revised
string program(string p) {
    string program = "";
    for (int i = 0; i < p.length(); i++) {
        if (p[i] >= 'A' && p[i] <= 'Z') {
            program += p[i];
        }
        else if (p[i] == '[') {
            i++;
            int k = 0;
            int j = i;
            for (; j < p.length() && p[j] >= '0' && p[j] <= '9'; j++) {
                k = k * 10 + p[j] - '0';
            }
            i = j;
            for (int l = 0; l < k; l++) {
                program += p[i];
            }
            i++;
        }
    }
    return program;
}
void insert(string pattern, int idx) {
    int cur = 1;
    for (int i = 0; i < pattern.length(); i++) {
        if (!tree[cur].child[pattern[i] - 'A']) {
            tree[cur].child[pattern[i] - 'A'] = ++cnt;
        }
        //cout << pattern[i] << " " << cur << " " << tree[cur].child[pattern[i] - 'A'] << endl;
        cur = tree[cur].child[pattern[i] - 'A'];
    }
    //cout << "insert: " << cur << " " << idx << endl;
    tree[cur].badnode = idx;
}
void prev() {
    tree[0].prev = -1;
    tree[1].prev = 0;
    for (int i = 0; i < 26; i++) {
        tree[0].child[i] = 1;
    }
    queue<int> q;
    int cur = 1;
    q.push(cur);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            if (tree[cur].child[i]) {
                int prev = cur;
                while (!tree[prev].child[i]) {
                    prev = tree[prev].prev;
                }
                tree[tree[cur].child[i]].prev = tree[prev].child[i];
                if (tree[tree[prev].child[i]].badnode)
                    tree[tree[cur].child[i]].badnode = tree[tree[prev].child[i]].badnode;
                q.push(tree[cur].child[i]);
            }
        }
    }
}
int search(string program) {
    int cur = 1;
    int viruscnt = 0;
    int virus[255];
    memset(virus, 0, sizeof(virus));
    for (int i = 0; i < program.length(); i++) {
        //cout << program[i] << " " << cur << " " << tree[cur].badnode << " " << tree[cur].child[program[i] - 'A'] << endl;
        while (!tree[cur].child[program[i] - 'A']) {
            cur = tree[cur].prev;
        }
        //cout << program[i] << " " << cur << " " << tree[cur].badnode << endl;
        cur = tree[cur].child[program[i] - 'A'];
        //cout << program[i] << " " << cur << " " << tree[cur].badnode << endl;
        if (tree[cur].badnode && !virus[tree[cur].badnode]) {
            virus[tree[cur].badnode] = true;
            viruscnt++;
        }
    }
    return viruscnt;
}
void test() {
    for (int i = 0; i <= cnt; i++) {
        cout << i << " " << tree[i].prev << " " << tree[i].badnode << endl;
    }
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        memset(tree, 0, sizeof(tree));
        cnt = 1;
        cin >> n;
        for (int j = 0; j < n; j++) {
            string virus;
            cin >> virus;
            insert(virus, j+1);
            reverse(virus.begin(), virus.end());
            insert(virus, j+1);
        }
        prev();
        //test();
        string p;
        cin >> p;
        p = program(p);
        cout << search(p) << endl;
    }
    return 0;
}