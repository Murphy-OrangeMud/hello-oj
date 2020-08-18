#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 55;
const int maxm = 55;
string dp[maxn][maxm];
int res[maxn];
string add(string a, string b)
{
    if (a.length() < b.length())
    {
        string tmp = a;
        a = b;
        b = tmp;
    }
    int lena = a.length();
    int lenb = b.length();
    memset(res, 0, sizeof(res));
    if (lena > lenb)
    {
        int d = 0;
        for (int i = 0; i < lenb; i++)
        {
            res[lena - i] = (a[lena - 1 - i] - '0' + b[lenb - 1 - i] - '0' + d) % 10;
            d = (a[lena - 1 - i] - '0' + b[lenb - 1 - i] - '0' + d) / 10;
        }
        for (int i = lenb; i < lena; i++)
        {
            res[lena - i] = (a[lena - 1 - i] - '0' + d) % 10;
            d = (a[lena - i - 1] - '0' + d) / 10;
        }
        res[0] = d;
    }
    else
    {
        int d = 0;
        for (int i = 0; i < lenb; i++)
        {
            res[lena - i] = (a[lena - 1 - i] - '0' + b[lenb - 1 - i] - '0' + d) % 10;
            d = (a[lena - 1 - i] - '0' + b[lenb - 1 - i] - '0' + d) / 10;
        }
        res[0] = d;
    }
    string ret = "";
    if (res[0])
    {
        ret += (res[0] + '0');
    }
    for (int i = 1; i <= lena; i++)
    {
        ret += (res[i] + '0');
    }
    //cout << a << " " << b << " " << ret << endl;
    return ret;
}
bool morethan(string a, string b)
{
    if (a == "") return true;
    else if (b == "") return false;
    else if (a.length() > b.length())
        return true;
    else if (a.length() == b.length())
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] > b[i])
                return true;
            else if (a[i] < b[i])
                return false;
        }
    }
    return false;
}
int main()
{
    string digits;
    int m;
    while (cin >> m >> digits)
    {
        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j < maxm; j++) {
                dp[i][j] = "";
            }
        }
        for (int i = 0; i < digits.length(); i++)
        {
            for (int j = 0; j <= min(i, m); j++)
            {
                if (j == 0)
                {
                    dp[i][j] = digits.substr(0, i + 1);
                }
                else
                {
                    for (int k = j-1; k < i; k++)
                    {
                        string res = add(dp[k][j - 1], digits.substr(k + 1, i - k));
                        if (!morethan(res, dp[i][j]))
                        {
                            dp[i][j] = res;
                        }
                    }
                }
            }
        }
        cout << dp[digits.length() - 1][m] << endl;
    }
    return 0;
}