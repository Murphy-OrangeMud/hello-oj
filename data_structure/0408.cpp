#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 1000005;
int nxt[maxn];
int init(string s) {
    nxt[0] = -1;
    nxt[1] = 0;
    for (int i = 1; i < s.length(); i++) {
        int k = nxt[i];
        while (k != -1 && s[i] != s[k]) {
            k = nxt[k];
        }
        nxt[i+1] = ++k;
    }
}
int ans[maxn];
int main() {
    int n;
    int kase = 0;
    string s;
    while (cin >> n && n) {
        cin >> s;
        memset(nxt, 0, sizeof(nxt));
        memset(ans, 0, sizeof(ans));
        init(s);
        for (int i = 2; i <= s.length(); i++) {
            if (i % (i - nxt[i]) == 0) ans[i] = i - nxt[i];
            else ans[i] = i;
        }
        cout << "Test case #" << ++kase << endl;
        for (int i = 2; i <= s.length(); i++) {
            if (ans[i] == i) continue;
            cout << i << " " << i / ans[i] << endl;
        }
        cout << endl;
    }
    return 0;
}