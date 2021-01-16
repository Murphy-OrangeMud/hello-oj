#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
    int dp[105][105][105][105][2];
bool isInterleave(string s1, string s2, string s3)
{
    if (s3.length() != s1.length() + s2.length())
        return false;
    if (s1.length() == 0 && s3 == s2)
        return true;
    if (s2.length() == 0 && s1 == s3)
        return true;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= s2.length(); i++)
    {
        if (s3[i - 1] != s2[i - 1])
            break;
        dp[0][1][0][i][1] = 1;
    }
    for (int i = 1; i <= s1.length(); i++)
    {
        if (s3[i - 1] != s1[i - 1])
            break;
        dp[1][0][i][0][0] = 1;
    }
    for (int seg = 1; seg <= min(s1.length(), s2.length()); seg++)
    {
        for (int i = 0; i <= s1.length(); i++)
        {
            for (int j = 0; j <= s2.length(); j++)
            {
                if (dp[seg - 1][seg][i][j][1])
                {
                    for (int k = i + 1; k <= s1.length(); k++)
                    {
                        if (s3[k + j - 1] != s1[k - 1])
                            break;
                        dp[seg][seg][k][j][1] = 1;
                    }
                }
                if (dp[seg][seg - 1][i][j][0])
                {
                    for (int k = j + 1; k <= s2.length(); k++)
                    {
                        if (s3[k + i - 1] != s2[k - 1])
                            break;
                        dp[seg][seg][i][k][0] = 1;
                    }
                }
                if (dp[seg][seg][i][j][0])
                {
                    for (int k = i + 1; k <= s1.length(); k++)
                    {
                        if (s3[k + j - 1] != s1[k - 1])
                            break;
                        dp[seg + 1][seg][k][j][0] = 1;
                    }
                }
                if (dp[seg][seg][i][j][1])
                {
                    for (int k = j + 1; k <= s2.length(); k++)
                    {
                        if (s3[k + i - 1] != s2[k - 1])
                            break;
                        dp[seg][seg + 1][i][k][1] = 1;
                    }
                }
            }
        }
    }
    for (int seg = 1; seg <= min(s1.length(), s2.length()); seg++)
    {
        if (dp[seg][seg][s1.length()][s2.length()][0] || dp[seg][seg][s1.length()][s2.length()][1] || dp[seg][seg - 1][s1.length()][s2.length()][0] || dp[seg - 1][seg][s1.length()][s2.length()][1])
            return true;
    }
    return false;
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << isInterleave(s1, s2, s3) << endl;
    return 0;
}