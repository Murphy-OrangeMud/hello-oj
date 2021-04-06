#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int t;cin>>t;
    while (t--) {
        int n; cin>>n;
        char c[10];char a[n+5],b[n+5];
        cin.getline(c,10);cin.getline(a,n+5),cin.getline(b,n+5);
        int s[n+5][2];memset(s,0,sizeof(s));
        s[1][a[0]-'0']++;
        for (int i=1;i<n;i++){
            s[i+1][a[i]-'0']=s[i][a[i]-'0']+1;
            s[i+1][!(a[i]-'0')]=s[i][!(a[i]-'0')];
        }
        vector<int> v;
        for (int i=1;i<=n;i++) {
            if (s[i][0] == s[i][1]) v.push_back(i);
        }
        bool flag = true;
        for (int i=0;i<v.size();i++) {
            for(int k=(i==0?1:v[i-1]+1);k<v[i];k++) {
                if ((a[k]-'0')^(b[k]-'0')!=(a[k-1]-'0')^(b[k-1]-'0')) {
                    flag = false;break;
                }
            }
            if(!flag)break;
        }
        for(int k = (v.size()==0?1:v[v.size()-1]+1); k< n; k++) {
            if ((a[k]-'0')^(b[k]-'0')!=(a[k-1]-'0')^(b[k-1]-'0')) {
                flag = false;break;
            }
        }
        if (flag) {
            int flip[v.size()+5];
            memset(flip,0,sizeof(flip));
            if (v.size()==0||v[v.size()-1]!=n) {
                if( (a[n-1]-'0')^(b[n-1]-'0')) {
                    flag = false;
                }
            }
            if (flag) {
                for (int i=v.size()-1;i>=0;i--) {
                    if ((a[v[i]-1]-'0')^(b[v[i]-1]-'0')!=(i==v.size()-1?0:((a[v[i+1]-1]-'0')^(b[v[i+1]-1]-'0')))) flip[i]=flip[i+1]+1;
                    else flip[i]=flip[i+1];
                }
                for (int i=v.size()-1; i>=0;i--) {
                    if (((a[v[i]-1]-'0')^(b[v[i]-1]-'0'))!=(flip[i]%2)) {
                        flag=false;break;
                    }
                }
            }
        }
        if(flag) cout<<"YES\n";
        else cout <<"NO\n";
    }
    return 0;
}