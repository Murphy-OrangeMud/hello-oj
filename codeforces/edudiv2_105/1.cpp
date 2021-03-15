#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    char c[10];
    cin.getline(c, 10);
    char s[55];
    while (t--) {
        cin.getline(s, 55);
        int a = 0, b = 0, c = 0;
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            if (s[i]=='A') a++;
            if (s[i]=='B') b++;
            if (s[i]=='C') c++;
        }
        stack<char> stk;
        bool flag = true;
        if (a == b + c) {
            if (s[0] == 'A') {
                for (int i = 0; i < len; i++) {
                    if (s[i] == 'A') {
                        stk.push('(');
                    }
                    else {
                        if (stk.empty()) {printf("NO\n");flag = false;break;}
                        stk.pop();
                    }
                }
                if (flag) printf("YES\n");
            }
            else {
                for (int i = 0; i < len; i++) {
                    if (s[i] != 'A') {
                        stk.push('(');
                    }
                    else {
                        if (stk.empty()) {printf("NO\n");flag = false;break;}
                        stk.pop();
                    }
                }
                if (flag) printf("YES\n");
            }
        }
        else if (b == a + c) {
            if (s[0] == 'B') {
                for (int i = 0; i < len; i++) {
                    if (s[i] == 'B') {
                        stk.push('(');
                    }
                    else {
                        if (stk.empty()) {printf("NO\n");flag = false;break;}
                        stk.pop();
                    }
                }
                if (flag) printf("YES\n");
            }
            else {
                for (int i = 0; i < len; i++) {
                    if (s[i] != 'B') {
                        stk.push('(');
                    }
                    else {
                        if (stk.empty()) {printf("NO\n");flag = false;break;}
                        stk.pop();
                    }
                }
                if (flag) printf("YES\n");
            }
        }
        else if (c == a + b) {
            if (s[0] == 'C') {
                for (int i = 0; i < len; i++) {
                    if (s[i] == 'C') {
                        stk.push('(');
                    }
                    else {
                        if (stk.empty()) {printf("NO\n");flag = false;break;}
                        stk.pop();
                    }
                }
                if (flag) printf("YES\n");
            }
            else {
                for (int i = 0; i < len; i++) {
                    if (s[i] != 'C') {
                        stk.push('(');
                    }
                    else {
                        if (stk.empty()) {printf("NO\n");flag = false;break;}
                        stk.pop();
                    }
                }
                if (flag) printf("YES\n");
            }
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}