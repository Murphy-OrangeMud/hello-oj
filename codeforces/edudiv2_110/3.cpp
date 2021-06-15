#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int i = 0, j = 1;
        int q_start = -1;
        long long cnt = 0;
        while (i < s.length() && j <= s.length()) {
            if (j-2 > i && s[j-2] != '?') q_start = -1; 
            if (s[j-1] == '?' && q_start < i) q_start = j-1;
            // cout << cnt << " " << i << " " << j << " " << q_start << endl;
            if (j - i >= 2 && s[j-1] != '?' && s[j-1] == s[j-2]) {
                i = j - 1;
            } else if (j - i >= 2 && q_start > i && s[j-1] != '?' && s[j-2] == '?') {
                if (s[j-1] == s[q_start - 1] && (j-1-q_start) % 2 == 0) {
                    i = q_start;
                } else if (s[j-1] != s[q_start - 1] && (j-1-q_start) % 2 == 1) {
                    i = q_start;
                }
            }
            cnt += (j-i); j++;
        }
        cout << cnt << endl;
    }
    return 0;
}
