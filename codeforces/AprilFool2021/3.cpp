#include<iostream>
#include <string>
using namespace std;
int main() {
    string s; cin >>s;
    for (int i = 2; i<s.length();i++){
        if ((s[i] -'A')%26 != ((int)(s[i-1]-'A')+(int)(s[i-2]-'A'))%26) {
            cout<<"NO\n";
            return 0;
        }
    }
    cout <<"YES\n";
    return 0;
}