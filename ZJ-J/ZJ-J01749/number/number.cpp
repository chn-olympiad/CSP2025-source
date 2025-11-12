#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int maxn = 15;
int vis[maxn];

signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n = s.size();
    for(int i = 0;i<n;++i)
    {
        if(isdigit(s[i]))
        {
            ++vis[s[i]-'0'];
        }
    }
    for(int i = 9;i>=0;--i)
    {
        while(vis[i])
        {
            printf("%lld",i);
            --vis[i];
        }
    }
    return 0;
}
