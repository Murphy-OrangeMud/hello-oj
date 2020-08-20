#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 105;
struct candy {
    int w, v;
    double ratio;
    candy(int _w, int _v) {
        w = _w;
        v = _v;
        ratio = (double)v*1.0 / w;
    }
    candy(){}
    bool operator < (const candy & other) const {
        return ratio > other.ratio;
    }
};
int main() {
    int n, mw;
    cin >> n >> mw;
    vector<candy> candies;
    for (int i = 0; i < n; i++) {
        int v, w;
        cin >> v >> w;
        candies.push_back(candy(w, v));
    }
    sort(candies.begin(), candies.end());
    double mv = 0;
    for (int i = 0; i < candies.size(); i++) {
        if (mw >= candies[i].w) {
            mw -= candies[i].w;
            mv += candies[i].v;
        }
        else {
            mv += candies[i].ratio * mw;
            mw = 0;
            break;
        }
    }
    printf("%.1f\n", mv);
    return 0;
}