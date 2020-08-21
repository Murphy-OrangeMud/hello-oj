// WA原因：没有看到题目中的条件：如果一条路径只有两棵水稻，则这个路径不是有效路径。
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 5005;
const int maxr = 5005;
const int maxc = 5005;
struct point {
    int x, y;
    point() {}
    point(int _x, int _y): x(_x), y(_y) {}
    bool operator < (const point & other) const {
        if (x < other.x) return true;
        else if (x == other.x) return y < other.y;
        return false;
    }
};
int visited[maxr][maxc];
int r, c, n;
int main() {
    cin >> r >> c >> n;
    vector<point> vec;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vec.push_back(point(x, y));
        visited[x][y] = 1;
    }
    sort(vec.begin(), vec.end());
    int maxnum = 2;
    for (int i = 0; i < n; i++) {
        if (vec[i].x > r / maxnum && vec[i].y > c / maxnum && (r - vec[i].x) > r / maxnum && (c - vec[i].y) > c / maxnum) continue;
        for (int j = i + 1; j < n; j++) {
            int dx = vec[j].x - vec[i].x;
            int dy = vec[j].y - vec[i].y;
            if (vec[i].x - dx >= 1 && vec[i].y - dy >= 1 && vec[i].x - dx <= r && vec[i].y - dy <= c) continue;
            if (vec[i].y + (maxnum - 1) * dy > c || 
                vec[i].x + (maxnum - 1) * dx > r || 
                vec[i].y + (maxnum - 1) * dy < 1 || 
                vec[i].x + (maxnum - 1) * dx < 1) continue;
            for (int k = 2; ; k++) {
                int nx = vec[i].x + dx * k;
                int ny = vec[i].y + dy * k;
                if (nx > r || ny > c || nx < 1 || ny < 1) {
                    maxnum = max(maxnum, k);
                    break;
                } else if (!visited[nx][ny]) {
                    break;
                }
            }

        }
    }
    if (maxnum == 2) maxnum = 0;
    cout << maxnum << endl;
    return 0;
}