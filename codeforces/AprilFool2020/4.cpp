#include<iostream>
using namespace std;
int main() {
    char c[10];
    cin.getline(c,10);
    cout << (c[6] - '0')%2 << endl;
    return 0;
}