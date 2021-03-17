#include<iostream>
#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> front;
        vector<int> back;
        unordered_map<int,int> u;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            if (u[x]) back.push_back(x);
            else front.push_back(x);
            u[x]++;
        }
        sort(front.begin(), front.end());
        for (int i = 0; i < front.size(); i++) {
            if (i) printf(" ");
            printf("%d", front[i]);
        }
        for (int i = 0; i < back.size(); i++) {
            printf(" %d", back[i]);
        }
        printf("\n");
    }
    return 0;
}