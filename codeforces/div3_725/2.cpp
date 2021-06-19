#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int sum = 0;
        vector<int> candy;
        for (int i = 0; i < n; i++) {
            int x; cin >> x; sum += x;
            candy.push_back(x);
        }
        if (sum % n) {
            cout << -1 << endl;
            continue;
        } else {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (candy[i] > sum/n) cnt++;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}