#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;cin>>n;
    vector<pair<long long, long long>> v;
    long long ans = 0 ;
    for (int i = 0; i < n; i++) {
        int a,c; cin>>a>>c; v.push_back(make_pair(a,c)); ans += c;
    }
    sort(v.begin(),v.end());
    long long mx = v[0].first+v[0].second;
    for (int i = 0; i < n;i++) {
        ans += max(v[i].first-mx,0ll);
        mx = max(mx,v[i].first+v[i].second);
    }
    cout<<ans<<'\n';
}