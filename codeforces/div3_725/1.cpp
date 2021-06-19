#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int maxa = 0,  mina = 101;
        int mini = -1, maxi = -1;
        vector<int> stones;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            stones.push_back(x);
            if (maxa < x) {
                maxa = x;
                maxi = i;
            }
            if (mina > x) {
                mina = x;
                mini = i;
            }
        }
        cout << min(n - min(maxi, mini), min(max(maxi, mini) + 1, min(maxi, mini) + 1 + n - max(maxi, mini))) << endl;
    }
    return 0;
}