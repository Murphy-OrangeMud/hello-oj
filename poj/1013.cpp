#include <iostream>
#include <string>
using namespace std;
const int LIGHT = 0;
const int HEAVY = 1;
struct state {
    string lhs, rhs, res;
};
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        state cur[3];
        for (int j = 0; j < 3; j++) {
            cin >> cur[j].lhs >> cur[j].rhs >> cur[j].res;
        }
        bool flag;
        for (char x = 'A'; x <= 'L'; x++) {
            for (int j = LIGHT; j <= HEAVY; j++) {
                flag = true;
                for (int k = 0; k < 3; k++) {
                    int l = cur[k].lhs.find(x);
                    int r = cur[k].rhs.find(x);
                    if (l == string::npos && r == string::npos && cur[k].res != "even") {flag = false; break;}
                    if (j == LIGHT && l != string::npos && cur[k].res != "down") {flag = false; break;}
                    if (j == LIGHT && r != string::npos && cur[k].res != "up") {flag = false; break;}

                    if (j == HEAVY && l != string::npos && cur[k].res != "up") {flag = false; break;}
                    if (j == HEAVY && r != string::npos && cur[k].res != "down") {flag = false; break;}
                }
                if (flag) {
                    string s = (j == LIGHT? "light": "heavy");
                    cout << x << " is the counterfeit coin and it is " << s << "." << endl;
                    break;
                }
            }
            if (flag) break;
        }
    }
    return 0;
}