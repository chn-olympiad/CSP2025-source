#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=5e3+13;
constexpr int mod=998244353;
constexpr int inf=(LONG_LONG_MAX>>1)-1;

int n;
int a[maxn];
int ans;
void sub1()
{
    for(int mask=7;mask<(1<<n);++mask)
    {
        int sum=0;
        int max_a=0;
        int tot=0;
        for(int i=1;i<=n;++i)
        {
            if(mask&(1LL<<(i-1)))
            {
                ++tot;
                sum+=a[i];
                max_a=max(max_a,a[i]);
            }
        }
        if(tot>=3&&sum>max_a*2)
        {
            ++ans;
        }
    }
    printf("%lld\n",ans%mod);
}
int fact[maxn];
int qpow(int a,int b,int p)
{
    if(a==1||b==0)
    {
        return 1;
    }
    int res=1;
    a%=p;
    while(b)
    {
        if(b&1)
        {
            res=(res*a)%p;
        }
        a=a*a%p;
        b>>=1;
        printf("1");
    }
    return res;
}
int inv[maxn];
int C(int a,int b)
{
    return fact[b]*inv[a]%mod*inv[b-a]%mod;
}
void sub2()
{
    fact[0]=1;
    inv[0]=1;
    for(int i=1;i<=n;++i)
    {
        fact[i]=fact[i-1]*i%mod;
        inv[i]=qpow(fact[i],mod-2,mod);
    }
    for(int i=3;i<=n;++i)
    {
        ans=(ans+C(i,n))%mod;
    }
    printf("%lld\n",ans);
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    if(n<=25)
    {
        sub1();
    }
    else if(a[n]<=1)
    {
        sub2();
    }
    else
    {
        sub2();
    }

    return 0;
}

