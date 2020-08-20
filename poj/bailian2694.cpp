#include <iostream>
#include <string>
#include <cmath>
using namespace std;
double poland() {
    string x;
    cin >> x;
    switch(x[0]) {
        case '+': return poland() + poland();
        case '-': return poland() - poland();
        case '*': return poland() * poland();
        case '/': return poland() / poland();
        default: return atof(x.c_str());
    }
}
int main() {
    printf("%.6f\n", poland());
    return 0;
}