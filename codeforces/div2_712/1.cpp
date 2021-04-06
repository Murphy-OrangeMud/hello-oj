#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    char c[10];
    cin.getline(c,10);
    while (t--) {
        char s[300005];
        cin.getline(s, 3e5+5);
        int len = strlen(s); int i;
        bool flag = false;
        if (len == 0) {
            cout <<"NO\n";
            continue;
        }
        for (i = 0; i < len/2; i++) {
            if (s[i] != 'a' || s[len-i-1] != 'a') flag = true;
            if (s[i] != s[len-i-1]) {
                char ret[300005];
                strcpy(ret, s);
                ret[i+1] = 'a';
                strcpy(ret+i+2,s+i+1);
                cout <<"YES\n";
                cout << ret << "\n";
                break;
            }
        }
        if (i == len/2) {
            if (flag == false && s[i] == 'a') {
                cout <<"NO\n";
                continue;
            }
            char ret[300005];
            ret[0] = 'a';
            strcpy(ret+1, s);
            cout <<"YES\n";
            cout << ret << "\n";
        }
    }
    return 0;
}