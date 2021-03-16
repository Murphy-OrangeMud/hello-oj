#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1005;
int parent[maxn];
int ans[maxn];

int ancester(int x) {
    if (parent[x] != -1 && parent[x] != x) {
        return ancester(parent[x]);
    }
    return x;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, pair<int,int>>> a;
    memset(parent, -1, sizeof(parent));
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int salary; scanf("%d", &salary);
            if (i == j) {
                ans[i] = salary;
                continue;
            }
            if (i > j) continue;
            a.push_back(make_pair(salary, make_pair(i,j)));
        }
    }
    sort(a.begin(), a.end());
    int idx = n;
    int head = -1;
    for (int i = 0; i < a.size(); i++) {
            int x = a[i].second.first;
            int y = a[i].second.second;
            if (a[i].first == ans[ancester(x)]) {
                parent[ancester(y)] = ancester(x);
            }
            else if (a[i].first == ans[ancester(y)]) {
                parent[ancester(x)] = ancester(y);
            }
            else {
                ans[idx] = a[i].first;
                if (ancester(x) != ancester(y)) {
                    parent[ancester(x)] = parent[ancester(y)] = idx++;
                }
                else {
                    head = ancester(x);
                    parent[head] = head;
                }
            }   
            //cout << x << " " <<y << " " << ancester(x) <<" "<< ancester(y) <<" "<< parent[ancester(x)] << " " << parent[ancester(y)] << endl;
            
    }
    printf("%d\n", idx);
    for (int i = 0; i < idx; i++) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    for (int i = 0; i < idx; i++) {
        if (parent[i] == -1 || parent[i] == i) printf("\n%d\n", i+1);
    }
    for (int i = 0; i < idx; i++) {
        if (parent[i] != -1 && parent[i] != i) printf("%d %d\n", i+1, parent[i]+1);
    }
    return 0;
}