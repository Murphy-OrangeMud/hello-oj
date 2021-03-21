#include <iostream>
#include <stack>
using namespace std;
const int mod = 1000000000;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int ctoi(char dir) {
    if (dir == 'N') return 0;
    else if (dir == 'E') return 1;
    else if (dir == 'S') return 2;
    else if (dir == 'W') return 3;
    else return -1;
}
struct state {
    long long deltax, deltay;
    long long repeat;
    state(int _r, int _x, int _y): deltax(_x), deltay(_y), repeat(_r){}
};
void solve(int kase) {
    stack<state> stk;
    string input;
    cin >> input;
    int i = 0;
    long long deltax = 0, deltay = 0;
    stk.push(state(1, 0, 0));
    while (i < input.length()) {
        if (input[i] >= '0' && input[i] <= '9') {
            state cur = stk.top();
            stk.pop();
            stk.push(state(cur.repeat, cur.deltax + deltax, cur.deltay + deltay));
            deltax = 0;
            deltay = 0;
            stk.push(state(input[i] - '0', 0, 0));
            i += 2;
        }
        else if (input[i] == ')') {
            state cur = stk.top();
            stk.pop();
            state cur2 = stk.top();
            stk.pop();
            deltax = ((deltax + cur.deltax) * cur.repeat) % mod;
            deltay = ((deltay + cur.deltay) * cur.repeat) % mod;
            stk.push(state(cur2.repeat, (cur2.deltax + deltax) % mod, (cur2.deltay + deltay) % mod));
            deltax = 0;
            deltay = 0;
            i++;
        }
        else {
            deltax = (deltax + dx[ctoi(input[i])]) % mod;
            deltay = (deltay + dy[ctoi(input[i])]) % mod;
            i++;
        }
    }
    cout << "Case #" << kase << ": " << (stk.top().deltay + deltay + mod) % mod + 1 << " " << (stk.top().deltax + deltax + mod) % mod + 1 << endl;
}
int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}