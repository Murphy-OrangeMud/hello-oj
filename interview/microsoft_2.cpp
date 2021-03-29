#include<iostream>
#include <cstring>
#include <string>
using namespace std;
string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string ten[10] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string tens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char str[10];
bool toInt(char *str, int &result) {
    int len = strlen(str);
    result = 0;
    for (int i = 0; i < len; i++){
        if(!(str[i] >='0' && str[i] <= '9')) {
            return false;
        }
        result = result * 10 + str[i]- '0';
    }
    if (result > 1000) return false;
    return true;
}

void func(int number) {
    if (number == 0) {
        cout << "zero" << endl;
        return;
    }
    int hundred = number / 100;
    if (hundred != 0) {
        cout << num[hundred] << " hundred"; 
    }
    int t = (number % 100) / 10;
    int n = (number % 100) % 10;
    if (t == 0) {
        if (n != 0) {
            if (hundred != 0) cout << " and ";
            cout << num[n] << endl;
        }
    } else if (t == 1) {
        if (hundred != 0) cout << " and ";
        cout << tens[n];
    } else {
        if (hundred != 0) cout << " and ";
        cout << ten[t];
        if (n != 0) {
            cout << "-" << num[n];
        }
    }
    cout << endl;
}

int main() {
    while (true) {
        cin >> str;
        int result;
        if (toInt(str, result)) {
            func(result);
        } else {
            cout <<"Invalid number" << endl;
        }
    }
    return 0;
}