// 看了题解，注意按钮对左右两边也有作用。另外注意memset。
#include <iostream>
#include <cstring>
using namespace std;
int lights[5];
int main() {
    int n;
    cin >> n;
    for (int kase = 1; kase <= n; kase++) {
        memset(lights, 0, sizeof(lights));
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                int x;
                cin >> x;
                lights[i] |= (x << j);
            }
        }
        int ans[5];
        memset(ans, 0, sizeof(ans));
        for (int first = 0; first < 64; first++) {
            //cout << "first" << first << endl;
            int j = 0;
            int button = first;
            bool flag = true;
            int tmp = lights[0];
            int state;
            while (j < 5) {
                ans[j] = button;
                state = tmp;
                for (int k = 0; k < 6; k++) {
                    if (button & (1 << k)) {
                        if (k > 0) {
                            state ^= (1 << (k - 1));
                        }
                        state ^= (1 << k);
                        if (k < 5) {
                            state ^= (1 << (k + 1));
                        }
                    }
                }
                //cout << state << endl;
                if (j < 4) tmp = lights[j+1] ^ button;
                button = state;
                j++;
            }
            if (!button) {
                cout << "PUZZLE #" << kase << endl;
                for (int i = 0; i < 5; i++) {
                    for (int k = 0; k < 6; k++) {
                        if (k) cout << " ";
                        cout << ((ans[i] >> k) & 1);
                    }
                    cout << endl;
                }
                break;
            }
        }
    }
    
    return 0;
}