#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    map<pair<int,int>,int> mm;
    int odd = 0; int even = 0;
    char c;
    for (int i = 0; i < m; i++) {
        cin >> c;
        switch(c) {
            case '+':{
                int u, v;
                char ch;
                cin >> u >> v >> c;
                mm[make_pair(u,v)] = c;
                if (mm[make_pair(v,u)]) even++;
                if (mm[make_pair(v,u)] == c) odd++;
                break;
            }
            case '-' :{
                int u, v;
                cin >> u >> v;
                if (mm[make_pair(v,u)]) even--;
                if (mm[make_pair(v,u)] == mm[make_pair(u,v)]) odd--;
                mm.erase(make_pair(u,v));
                break;
            }
            case '?': {
                int k; cin >> k;
                if ((k % 2 == 1 && even > 0) || (k % 2 == 0 && odd > 0)) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
    return 0;
}