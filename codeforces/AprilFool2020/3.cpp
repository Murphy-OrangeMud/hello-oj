#include<iostream>
using namespace std;

int main() {
    int x; cin >> x;
    int y;
    if (x/32) y+=32;
    if ((x%32)/16) y+=1;
    if ((x%16)/8) y+=4;
    if ((x%8)/4) y+=8;
    if ((x%4)/2) y+=2;
    if ((x%2)) y+=16;
    cout << y<<"\n";
    return 0;
}