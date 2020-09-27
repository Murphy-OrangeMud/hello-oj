//alpha-beta pruning
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 0xffffff;
vector<pair<int,int>> neighbor[10][10];
int map[10][10];
int alpha_search(int xa, int ya, int xb, int yb, int sa, int sb, bool flag);
int beta_search(int xa, int ya, int xb, int yb, int sa, int sb, bool flag);
void init(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2*i-1; j++) {
            if (j % 2 == 0) {
                neighbor[i][j].push_back(make_pair(i-1,j-1));
                neighbor[i][j].push_back(make_pair(i, j-1));
                neighbor[i][j].push_back(make_pair(i, j+1));
            }
            else {
                if (j > 1) neighbor[i][j].push_back(make_pair(i, j-1));
                if (j < 2*i-1) neighbor[i][j].push_back(make_pair(i, j+1));
                if (i < n) neighbor[i][j].push_back(make_pair(i+1, j+1));
            }
        }
    }
}
int beta_search(int xa, int ya, int xb, int yb, int sa, int sb, bool flag) {
    int minimum = inf;
    int tmpx = -1, tmpy = -1;
    for (int i = 0; i < neighbor[xb][yb].size(); i++) {
        int xxb = neighbor[xb][yb][i].first;
        int yyb = neighbor[xb][yb][i].second;
        if (map[xxb][yyb]) continue;
        if (xxb == xa && yyb == ya) continue;
        map[xxb][yyb] = 1;
        int tmpscore = alpha_search(xa, ya, xxb, yyb, sa, sb + 1, true);
        map[xxb][yyb] = 0;
        if (tmpscore < minimum) {
            minimum = tmpscore;
            tmpx = xxb;
            tmpy = yyb;
        }
    }
    if (minimum != inf) return minimum;
    if (flag == false && minimum == inf) return sa - sb;
    int xxb = xb, yyb = yb;
    int tmpscore = alpha_search(xa, ya, xxb, yyb, sa, sb, false);
    if (tmpscore < minimum) {
        minimum = tmpscore;
        tmpx = xxb;
        tmpy = yyb;
    }
    if (minimum == inf) return sa - sb;
    else {
        //alpha_search(xa, ya, xb, yb, sa, sb);
        //map[tmpx][tmpy] = 1;
        return minimum;
    }
}
int alpha_search(int xa, int ya, int xb, int yb, int sa, int sb, bool flag) {
    int maximum = -inf;
    int tmpx = -1, tmpy = -1;
    for (int i = 0; i < neighbor[xa][ya].size(); i++) {
        int xxa = neighbor[xa][ya][i].first;
        int yya = neighbor[xa][ya][i].second;
        if (map[xxa][yya]) continue;
        if (xxa == xb && yya == yb) continue;
        map[xxa][yya] = 1;
        int tmpscore = beta_search(xxa, yya, xb, yb, sa + 1, sb, true);
        map[xxa][yya] = 0;
        if (tmpscore > maximum) {
            maximum = tmpscore;
            tmpx = xxa;
            tmpy = yya;
        }
    }
    if (maximum != -inf) return maximum;
    if (flag == false && maximum == -inf) return sa - sb;
    int xxa = xa, yya = ya;
    int tmpscore = beta_search(xxa, yya, xb, yb, sa, sb, false);
    if (tmpscore > maximum) {
        maximum = tmpscore;
        tmpx = xxa;
        tmpy = yya;
    }
    if (maximum == -inf) return sa - sb;
    else {
        //beta_search(xa, ya, xb, yb, sa, sb);
        //map[tmpx][tmpy] = 1;
        return maximum; 
    }
}
void solve() {
    memset(map, 0, sizeof(map));
    memset(neighbor, 0, sizeof(neighbor));
    int s, ra, ca, rb, cb, c;
    cin >> s >> ra >> ca >> rb >> cb >> c;
    for (int i = 0; i < c; i++) {
        int rr, cc;
        cin >> rr >> cc;
        map[rr][cc] = 1;
    }
    init(s);
    map[ra][ca] = 1;
    map[rb][cb] = 1;
    int score = alpha_search(ra, ca, rb, cb, 1, 1, true);
    cout << score << endl;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}