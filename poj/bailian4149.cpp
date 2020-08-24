#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 16;
const int maxst = (1 << 15) + 10;
struct state
{
    string path;
    int score;
    int t;
    state()
    {
        t = 0;
        score = 0xffffff;
        path = "";
    }
};
int n;
string name[maxn];
int d[maxn];
int c[maxn];
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        memset(d, 0, sizeof(d));
        memset(c, 0, sizeof(c));
        for (int j = 0; j < n; j++)
        {
            cin >> name[j] >> d[j] >> c[j];
        }
        int maxstate = (1 << n);
        state dp[maxstate];
        dp[0].score = 0;
        dp[0].path = "";
        for (int i = 0; i < n; i++)
        {
            dp[(1 << i)].score = max(0, c[i] - d[i]);
            dp[(1 << i)].path = name[i] + "\n";
            dp[(1 << i)].t = c[i];
        }
        for (int i = 0; i < maxstate; i++)
        {
            string temp = dp[i].path;
            for (int j = 0; j < n; j++)
            {
                if (!(i & (1 << j)))
                    continue;
                //cout << "statechange: " << i << " " << (i & (~(1 << j))) << " " << dp[i].score << " " << dp[(i & (~(1 << j)))].score << endl;
                if (dp[i].score > dp[i & (~(1 << j))].score + max(0, dp[i & (~(1 << j))].t + c[j] - d[j]))
                {
                    dp[i].score = dp[i & (~(1 << j))].score + max(0, dp[i & (~(1 << j))].t + c[j] - d[j]);
                    dp[i].t = dp[i & (~(1 << j))].t + c[j];
                    //cout << temp << endl;
                    temp = dp[(i & (~(1 << j)))].path + name[j] + "\n";
                    //cout << temp << endl;
                }
                else if (dp[i].score == dp[i & (~(1 << j))].score + max(0, dp[i & (~(1 << j))].t + c[j] - d[j]))
                {
                    if (dp[(i & (~(1 << j)))].path + name[j] < temp)
                    {
                        dp[i].t = dp[(i & (~(1 << j)))].t + c[j];
                        temp = dp[(i & (~(1 << j)))].path + name[j] + "\n";
                    }
                }
            }
            dp[i].path = temp;
        }
        state res = dp[(1 << n) - 1];
        cout << res.score << endl
             << res.path;
    }
    return 0;
}