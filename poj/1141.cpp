#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 105;
int dp[maxn][maxn];
int path[maxn][maxn];
char brackets[maxn];
void print(int i, int j) {
    //cout << i << " " << j << " " << path[i][j] << endl;
    if (i == j) {
        if (brackets[i] == '(' || brackets[i] == ')')
            cout << "()";
        else
            cout << "[]";
    }
    else if (i > j) return;
    else {
        if (path[i][j] != -1) {
            print(i, path[i][j]);
            print(path[i][j] + 1, j);
        }
        else {
            if (dp[i][j] == 0) {
                for (int k = i; k <= j; k++) {
                    cout << brackets[k];
                }
            }
            else {
                cout << brackets[i];
                print(i+1, j-1);
                cout << brackets[j];
            }
        }
    }
}
void func() {
    cin.getline(brackets, maxn);
    int len = strlen(brackets);
    memset(dp, 1, sizeof(dp));
    memset(path, -1, sizeof(path));
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
    }
    for (int i = len-1; i >= 0; i--) {
        for (int j = i + 1; j < len; j++) {
            if (brackets[i] == '(' && brackets[j] == ')' ||
                brackets[i] == '[' && brackets[j] == ']') {
                    if (j - i == 1) dp[i][j] = 0;
                    else {
                        dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
                    }
                }
            for (int k = i; k < j; k++) {
                if (dp[i][k] + dp[k+1][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k+1][j];
                    path[i][j] = k;
                }
            }
        }
    }
    print(0, len-1);
    cout << endl;
}
int main() {
    func();
    return 0;
}