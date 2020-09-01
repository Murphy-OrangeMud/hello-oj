#include <iostream>
#include <queue>
using namespace std;
struct node {
    int weight;
    int total;
    node *l, *r;
    node(int _total = 0, int _weight = 0, node *_l = NULL, node *_r = NULL): l(_l), r(_r), weight(_weight), total(_total) {}
    bool operator <(const node & other) const {
        return weight > other.weight;
    }
};
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        priority_queue<node> pq;
        node cur;
        for (int j = 0; j < n; j++) {
            cin >> cur.weight;
            pq.push(cur);
        }
        node ccur;
        while (!pq.empty()) {
            cur = pq.top();
            pq.pop();
            if (pq.empty()) break;
            ccur = pq.top();
            pq.pop();
            pq.push(node(cur.total + ccur.total + cur.weight + ccur.weight, cur.weight + ccur.weight, new node(cur.total, cur.weight, cur.l, cur.r), new node(ccur.total, ccur.weight, ccur.l, ccur.r)));
        }
        cout << cur.total << endl;
    }
    return 0;
}