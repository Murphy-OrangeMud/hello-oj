#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        int flag = -1;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int v;
            cin >> v;
            if (v == k) {
                flag = k;
            }
            else if (v == flag - 1) {
                flag--;
                if (v == 1) {
                    cnt++;
                    flag = -1;
                }
            }
            else if (flag != -1) {
                flag = -1;
            }
        }
        cout << "Case #" << i+1 << ": " << cnt << endl;
    }
    return 0;
}