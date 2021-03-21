#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int map[5][5];
vector<pair<int,int>> neighbor[5][5];
void init() {
    neighbor[1][1].push_back(make_pair(2,2));
    neighbor[2][1].push_back(make_pair(2,2));
    neighbor[2][3].push_back(make_pair(2,2));
    neighbor[2][2].push_back(make_pair(2,1));
    neighbor[2][2].push_back(make_pair(2,3));
    neighbor[2][2].push_back(make_pair(1,1));
}
void solve() {
    memset(map, 0, sizeof(map));
    int s, ra, ca, rb, cb, c;
    cin >> s >> ra >> ca >> rb >> cb >> c;
    for (int i = 0; i < c; i++) {
        int rr, cc;
        cin >> rr >> cc;
        map[rr][cc] = 1;
    }
    map[ra][ca] = 1;
    map[rb][cb] = 1;
    bool flag = true;
    int sa = 1, sb = 1;
    int xa = ra, ya = ca, xb = rb, yb = cb;
    while (flag) {
        flag = false;
        // A round
        for (int i = 0; i < neighbor[xa][ya].size(); i++) {
            int xxa = neighbor[xa][ya][i].first;
            int yya = neighbor[xa][ya][i].second;
            if (map[xxa][yya]) continue;
            if (xb == xxa && yb == yya) continue;
            sa++;
            flag = true;
            xa = xxa;
            ya = yya;
            map[xxa][yya] = 1;
            break;
        }
        // B round
        for (int i = 0; i < neighbor[xb][yb].size(); i++) {
            int xxb = neighbor[xb][yb][i].first;
            int yyb = neighbor[xb][yb][i].second;
            if (map[xxb][yyb]) continue;
            if (xa == xxb && ya == yyb) continue;
            sb++;
            flag = true;
            xb = xxb;
            yb = yyb;
            map[xxb][yyb] = 1;
            break;
        }
    }
    cout << sa - sb << endl;
}
int main() {
    init();
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}