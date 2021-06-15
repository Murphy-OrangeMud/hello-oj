#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int s1, s2, s3, s4;
        cin >> s1 >> s2 >> s3 >> s4;
        vector<int> a;
        vector<int> b;
        b.push_back(s1); b.push_back(s2); b.push_back(s3); b.push_back(s4);
        a.push_back(max(s1, s2));
        a.push_back(max(s3, s4));
        sort(b.begin(), b.end());
        if (max(a[0], a[1]) == b[3] && min(a[0], a[1]) == b[2]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}