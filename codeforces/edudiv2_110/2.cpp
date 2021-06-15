#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (a < b) {
        int tmp = a; a = b; b = tmp;
    }
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> even, odd;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x % 2) odd.push_back(x);
            else even.push_back(x);
        }
        int cnt = 0;
        for (int i = 0; i < odd.size(); i++) {
            for (int j = i + 1; j < odd.size(); j++) {
                if (gcd(odd[i], odd[j]) > 1) cnt++;
            }
        }
        cnt += (n-1+n-even.size())*even.size()/2;
        cout << cnt << endl;
    }
    return 0;
}