#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e3+10;
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a[maxn];
    int dp[maxn][maxn];
    int n,k;
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
    }
    for(int l=1;l<=n;++l)
    {
        for(int r=l;r<=n;++r)
        {
            int p=0;
            for(int i=l;i<=r;++i)
            {
                p^=a[i];
            }
            if(p==k)
            {
                dp[l][r]=1;

            }
        }
    }
    for(int j=1;j<=n;++j)
    {
        for(int z=1;z<=j;++z)
        {
            for(int y=j;y<=n;++y)
            {
                if(z!=y)
                {
                    dp[z][y]=max(dp[z][y],dp[z][j]+dp[j][y]);
                }
            }
        }
    }
    printf("%lld\n",dp[1][n]);
    return 0;
}
