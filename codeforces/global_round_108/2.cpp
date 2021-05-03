#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n%2) cout << "NO\n";
        else if (sqrt(n/2) == (int)(sqrt(n/2))) cout << "YES\n";
        else if (sqrt(n) == (int)(sqrt(n))) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}