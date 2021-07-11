#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long a, b; cin >> a >> b;
        if (a < b) { a = a + b; b = a - b; a = a - b; }
        if (a-b == 0) cout << "0 0\n";
        else {
            cout << a-b << " " << min(a%(a-b), a-b-a%(a-b)) << endl; 
        }
    }
    return 0;
}