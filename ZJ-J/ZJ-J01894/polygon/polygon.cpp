#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e4+10;
constexpr int mod=998244353;
int a[maxn];
int f=1;
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%lld",&n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%lld",a+i);
        if(a[i]!=1) f=0;
    }
    sort(a+1,a+1+n);
    if(n==3)
    {
        if(a[3]*2>a[1]+a[2]) printf("1\n");
        else printf("0\n");
        return 0;
    }
    else if(f)
    {
        int ans=0;
        for(int i=2; i<n; ++i)
        {
            ans+=n-i;
            ans%=mod;
        }
        printf("%lld\n",ans);
    }


    return 0;
}