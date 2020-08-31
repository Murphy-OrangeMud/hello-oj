//WA：没有加特判（序列完之后栈必须是空的，而且序列输入当中栈也可能空）
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<string> vec;
    stack<int> stk;
    int idx = 1;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        while (v >= idx) {
            if (v > n) {
                cout << "NO" << endl;
                return 0;
            }
            stk.push(idx);
            vec.push_back("PUSH " + to_string(idx));
            idx++;
        }
        if (stk.empty()) {
            cout << "NO" << endl;
            return 0;
        }
        if (v == stk.top()) {
            stk.pop();
            vec.push_back("POP " + to_string(v));
        }
    }
    if (!stk.empty()) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    return 0;
}