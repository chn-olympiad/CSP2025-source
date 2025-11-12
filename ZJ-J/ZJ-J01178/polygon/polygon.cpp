#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int mod=998244353;
constexpr int maxn=5e3+10;
int sum[maxn];
int ma;
int n;
int ans;
int a[maxn];
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    sum[0]=0;
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",a+i);
        sum[i]=sum[i-1]+a[i];
        ma=max(ma,a[i]);
    }
    if(n<=3)
    {
        if(sum[n]>2*ma)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
        return 0;
    }
    if(ma*2<sum[n])
    {
        ++ans;
    }
    for(int l=1;l<=n-3;++l)
    {
        for(int i=n;i-l+1>=1;--i)
        {
            int j=i-l+1;
            int ss=sum[j-1]+sum[n]-sum[i];
            ma=0;
            for(int k=1;k<j;++k)
            {
                ma=max(ma,a[k]);
            }
            for(int k=i+1;k<=n;++k)
            {
                ma=max(ma,a[k]);
            }
            if(2*ma<ss)
            {
                ++ans;
                ans%=mod;
            }
        }
    }
    printf("%lld\n",ans%mod);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int mod=998244353;
constexpr int maxn=5e3+10;
int sum[maxn];
int ma;
int n;
int ans;
int a[maxn];
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    sum[0]=0;
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",a+i);
        sum[i]=sum[i-1]+a[i];
        ma=max(ma,a[i]);
    }
    if(n<=3)
    {
        if(sum[n]>2*ma)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
        return 0;
    }
    if(ma*2<sum[n])
    {
        ++ans;
    }
    for(int l=1;l<=n-3;++l)
    {
        for(int i=n;i-l+1>=1;--i)
        {
            int j=i-l+1;
            int ss=sum[j-1]+sum[n]-sum[i];
            ma=0;
            for(int k=1;k<j;++k)
            {
                ma=max(ma,a[k]);
            }
            for(int k=i+1;k<=n;++k)
            {
                ma=max(ma,a[k]);
            }
            if(2*ma<ss)
            {
                ++ans;
                ans%=mod;
            }
        }
    }
    printf("%lld\n",ans%mod);
    return 0;
}
