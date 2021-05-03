#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct tower {
    int height;
    int idx;
    tower() {}
    tower(int _idx, int _height): idx(_idx), height(_height) {}
    bool operator < (const tower & other) const {
        if (height > other.height) return true;
        else if (height == other.height) return idx > other.idx;
        return false;
    }
};

struct block {
    int idx;
    int height;
    int tower;
    block() {}
    block(int _idx, int _height, int _tower=-1): idx(_idx), height(_height), tower(_tower) {}
    bool operator < (const block & other) const {
        if (height < other.height) return true;
        else if (height == other.height) return idx < other.idx;
        return false;
    }
};

bool compare(const block &a, const block &b) {
    return a.idx < b.idx;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, x; cin >> n >> m >> x;
        priority_queue<tower> tpq;
        vector<block> blk;
        int blkno = n;
        for (int i = 0; i < m; i++) {
            tpq.push(tower(i, 0));
        }
        for (int i = 0; i < n; i++) {
            int h; cin >> h;
            blk.push_back(block(i, h));
        }
        sort(blk.begin(), blk.end());
        while (blkno > 0) {
            tower cur = tpq.top();
            tpq.pop();
            blk[blkno-1].tower = cur.idx;
            tpq.push(tower(cur.idx, cur.height + blk[blkno-1].height));
            blkno--;
        }
        vector<tower> towers;
        int maxt = 0, mint = 2e9;
        while (!tpq.empty()) {
            maxt = max(tpq.top().height, maxt);
            mint = min(tpq.top().height, mint);
            tpq.pop();
        }
        if (maxt - mint > x) cout << "NO\n";
        else {
            cout << "YES\n";
            sort(blk.begin(), blk.end(), compare);
            for (int i = 0; i < n; i++) {
                if (i) cout << " ";
                cout << blk[i].tower+1;
            }
            cout << endl;
        }
    }
    return 0;
}