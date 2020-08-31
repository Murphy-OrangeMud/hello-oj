#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char c[205];
    bool comment = false;
    bool string = false;
    while (cin.getline(c, 205)) {
        strcat(c, "\n");
        int len = strlen(c);
        for (int i = 0; i < len; i++) {
            if (comment) {
                if (c[i-1] == '*' && c[i] == '/') {
                    comment = false;
                }
                continue;
            }
            else if (string) {
                if (c[i-1] != '\\' && c[i] == '\"'){
                    string = false;
                }
            }
            else {
                if (c[i] == '\"' && (i == 0 || c[i-1] != '\\')) {
                    string = true;
                }
                else if (c[i] == '/' && c[i+1] == '*') {
                    i++;
                    comment = true;
                }
            }
            if (!comment) cout << c[i];
        }
    }
    return 0;
}