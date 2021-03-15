#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        vector<long long> mine;
        vector<long long> miner;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 2*n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x==0) miner.push_back(abs((long long)y));
            if (y==0) mine.push_back(abs((long long)x));
        }
        sort(mine.begin(), mine.end());
        sort(miner.begin(), miner.end());
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += sqrt(mine[i]*mine[i]+miner[i]*miner[i]);
        }
        printf("%.9f\n", sum);
    }
    return 0;
}