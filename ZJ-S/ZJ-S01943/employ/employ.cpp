#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e7+10;
constexpr int mod=998244353;
char c[maxn];
int a[maxn],tmp=0;
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,fa=1;
    scanf("%lld%lld",&n,&m);
    for(int i=1; i<=n; ++i)
    {
        scanf(" %c",&c[i]);
        if(c[i]=='0')
        {
            fa=0;
        }
    }
    for(int i=1; i<=n; ++i)
    {
        scanf("%lld",a+i);
        if(a[i]==0) ++tmp;
    }
    if(m==n)
    {
        int ans=1;
        for(int i=n; i>=tmp; --i)
        {
            ans*=i;
            ans%=mod;
        }
        printf("%lld\n",(ans+mod)%mod);
        return 0;
    }
    


    return 0;
}