#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1e5+5;
char s[3][maxn*2];

int main() {
    int t;cin>>t;
    while (t--) {
        int n;cin>>n;
        char c[10]; cin.getline(c,10);
        for (int i = 0; i < 3;  i++) {
            cin.getline(s[i], 2*n+5);
        }
        int p[3]; memset(p,0,sizeof(p));
        vector<char> ans;
        bool flag = true;
        int j0 = -1;
        while (flag) {
            for (int j = 0; j < 3; j++) {
                if (s[j][p[j]] == s[(j+1)%3][p[(j+1)%3]]) {
                    ans.push_back(s[j][p[j]]);
                    p[j]++; p[(j+1)%3]++;
                    if (s[j][p[j]-1] == s[(j+2)%3][p[(j+2)%3]]) p[(j+2)%3]++;
                    break;
                }
            }
            for (int j = 0; j < 3; j++) {
                if (p[j] >= 2*n) { flag = false; j0 = j; break;}
            }
        }
        if (p[(j0+1)%3] > p[(j0+2)%3]) j0 = (j0+1)%3;
        else j0 = (j0+2)%3;
        for (int i = p[j0]; i < 2*n; i++) {
            ans.push_back(s[j0][i]);
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}