#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e5+10;
constexpr int maxn2=1e3+10;
int xl[maxn];
int qzh[maxn];
int dp[maxn2][maxn2];
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%lld%lld",&n,&k);
    bool A=true;
    bool B=true;
    int cnt1=0;
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&xl[i]);
        if(xl[i]!=1)
        {
            A=false;
        }
        if(xl[i]>1)
        {
            B=false;
        }
        if(B&&xl[i])
        {
            ++cnt1;
        }
        qzh[i]=qzh[i-1]^xl[i];
    }
    if(A)
    {
        printf("%lld\n",n>>1);
        return 0;
    }
    if(B)
    {
        if(k)
        {
            printf("%lld\n",cnt1);
        }
        else
        {
            int res=0;
            for(int i=1;i<=n;++i)
            {
                if(xl[i]&&xl[i+1])
                {
                    ++res;
                    ++i;
                }
                else if(!xl[i])
                {
                    ++res;
                }
            }
            printf("%lld\n",res);
        }
        return 0;
    }
    if(n<maxn2)
    {
        for(int len=1;len<=n;++len)
        {
            for(int l=1;l+len-1<=n;++l)
            {
                int r=l+len-1;
                if((qzh[r]^qzh[l-1])==k)
                {
                    dp[l][r]=1;
                }
                for(int kk=l;kk<r;++kk)
                {
                    dp[l][r]=max(dp[l][r],dp[l][kk]+dp[kk+1][r]);
                }
            }
        }
        printf("%lld\n",dp[1][n]);
        return 0;
    }
}