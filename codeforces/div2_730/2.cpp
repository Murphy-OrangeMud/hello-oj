#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        long long sum = 0;
        for (int i = 0; i < n; i++ ) {
            int x; cin >> x; sum += x;
        }
        if (sum % n == 0) cout << 0 << endl;
        else {
            cout << (sum%n)*(n-(sum%n)) << endl;
        }
    }
    return 0;
}