#include <iostream>
using namespace std;
const int maxn = 10;
int n;
int result[maxn];
int used[maxn];
void permutations(int i) {
    if (i == n) {
        for (int j = 0; j < n; j++) {
            if (j) cout << " ";
            cout << result[j];
        }
        cout << endl;
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (used[j]) continue;
        result[i] = j;
        used[j] = 1;
        permutations(i+1);
        used[j] = 0;
    }
    return;
}
int main() {
    while (cin >> n && n) permutations(0);
    return 0;
}