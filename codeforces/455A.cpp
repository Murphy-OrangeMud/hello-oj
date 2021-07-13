#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int maxn = 1e5+5;
int main() {
    int n; cin >> n;
    vector<long long> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; a.push_back(x);
    }
    sort(a.begin(), a.end());
    map<long long, long long> aa;
    for (int i = 0; i < a.size(); i++) {
        aa[a[i]]++;
    }
    long long dp[aa.size() + 5][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0; dp[0][1] = aa[0];
    int idx = 0;
    for (auto key: aa) {
        if (!idx) {
            idx++;
            continue;
        }
        if (aa[key.first-1]) {
            dp[idx][0] = max(dp[idx-1][0], dp[idx-1][1]);
            dp[idx][1] = dp[idx-1][0] + key.first * key.second;
        } else {
            dp[idx][0] = max(dp[idx-1][0], dp[idx-1][1]);
            dp[idx][1] = max(dp[idx-1][0], dp[idx-1][1]) + key.first * key.second;
        }
        idx++;
    }
    cout << max(dp[idx-1][0], dp[idx-1][1]) << endl;
    return 0;
}