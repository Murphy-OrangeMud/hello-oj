#include <iostream>
#include <cmath>
using namespace std;
const int inf = 0xffffff;
const int maxh = 10005;
const int maxr = 105;
const int maxm = 25;
int mins = inf;
int minsurface[maxr][maxh][maxm];
bool dfs(int ri, int hi, int layer, int s, int remainv) {
    //cout << ri << " " << hi << " " << layer << " " << s << " " << remainv << endl;
    if (layer == 1) {
        if (remainv == 0) {
            mins = min(mins, s + ri * ri);
            return true;
        }
        return false;
    }
    bool flag = false;
    for (int r = ri - 1; r > 0; r--) {
        if (r < layer - 1) break;
        for (int h = hi - 1; h > 0; h--) {
            //cout << h << " " << layer << endl;
            if (h < layer - 1) break;
            //cout << h << " " << layer << endl;
            if (remainv - r*r*h < 0) continue;
            if (remainv - r*r*h*(layer - 1) > 0) continue;
            if (s + (ri*ri-r*r) + 2*r*h >= mins) continue;
            //if (minsurface[r][h][layer-1] < s + (ri*ri-r*r) + 2*r*h) continue;
            dfs(r, h, layer - 1, s + (ri*ri-r*r) + 2*r*h, remainv - r*r*h);
            /*
            if (dfs(r, h, layer - 1, s + (ri*ri-r*r) + 2*r*h, remainv - r*r*h)) {
                minsurface[r][h][layer-1] = min(minsurface[r][h][layer-1], s + (ri*ri-r*r) + 2*r*h);
                flag = true;
            }*/
        }
    }
    return flag;
}
int main() {
    int n, m;
    cin >> n >> m;
    int mar = int(sqrt((double)n)) + 1;
    int mah = n;
    int mir = m;
    int mih = m;
    for (int r = mar - 1; r >= mir; r--) {
        for (int h = mah - 1; h >= mih; h--) {
            if (2*r*h > mins) continue;
            if (n - r * r * h < 0) continue;
            dfs(r, h, m, 2*r*h, n - r * r * h);
        }
    }
    if (mins == inf) cout << 0 << endl;
    else cout << mins << endl;
    return 0;
}