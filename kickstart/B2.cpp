// attention: not AC but cannot find the bug.
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const long long maxD = (long long)1e12;
const int maxn = 1005;
long long D;
int n;
long long x[maxn];
long long finish(long long start)
{
    long long finishtime = start;
    for (int i = 0; i < n; i++)
    {
        finishtime = ((finishtime + x[i] - 1) / x[i]) * x[i];
    }
    return finishtime;
}
long long solve()
{
    long long mind = 1, maxd = D;
    long long mid = (mind + maxd) / 2;
    while (mind < maxd)
    {
        mid = (mind + maxd) / 2;
        long long finish1 = finish(mid);
        long long finish2 = finish(mid+1);
        if (finish1 <= D && finish2 > D) {
            return mid;
        }
        else if (finish1 > D)
        {
            maxd = mid - 1;
        } 
        else {
            mind = mid + 1;
        }
    }
    return mind;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> D;
        memset(x, 0, sizeof(x));
        for (int j = 0; j < n; j++)
        {
            cin >> x[j];
        }
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}