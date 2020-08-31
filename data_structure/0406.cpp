#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<string> hw;
    for (int i = 0; i < n; i++) {
        string v;
        cin >> v;
        hw.push_back(v);
    }
    string model;
    cin >> model;
    int cnt = n;
    for (int i = 0; i < n; i++) {
        int im = 0, ih = 0;
        bool t = true;
        while (im < model.length() && ih < hw[i].length()) {
            if (model[im] != '[') {
                if (abs(model[im] - hw[i][ih]) != 0 && abs(model[im] - hw[i][ih]) != 32) {
                    t = false;
                    break;
                }
                im++;
                ih++;
            }
            else {
                im++;
                int j = im;
                bool flag = false;
                for (; model[j] != ']'; j++) {
                    if (abs(model[j] - hw[i][ih]) == 0 || abs(model[j] - hw[i][ih]) == 32) {
                        flag = true;
                    }
                }
                if (flag) {
                    im = j + 1;
                    ih++;
                }
                else {
                    t = false;
                    break;
                }
            }
        }
        if (t && (im != model.length() || ih != hw[i].length())) {
            t = false;
        }
        if (t) {
            cout << i+1 << " " << hw[i] << endl;
        }
    }
    return 0;
}