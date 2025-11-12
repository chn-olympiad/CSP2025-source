#include<bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int mod=998244353,maxn=5e3+10,maxm=3e7+10;
int ans=0;
int fact[maxn],inv[maxn],invfact[maxn];
void init()
{
    fact[0]=1;
    for(int i=1;i<maxn;++i)
    {
        fact[i]=fact[i-1]*i%mod;
    }
    inv[1]=1;
    for(int i=2;i<maxn;++i)
    {
        inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    }
    invfact[0]=1;
    for(int i=1;i<maxn;++i)
    {
        invfact[i]=invfact[i-1]*inv[i]%mod;
    }
}
int C(int m,int k)
{
    return fact[m]*invfact[k]%mod*invfact[m-k]%mod;
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%lld",&n);
    vector<int>a(n+1),pre(n+1);
    int is1=1;
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        pre[i]=pre[i-1]+a[i];
        if(a[i]!=1)
        {
            is1=0;
        }
    }
    init();
    if(n<=20)
    {
        for(int o=0;o<=(1ll<<n)-1;++o)
        {
            int cnt=0,mx=0,z=0;
            for(int i=1;i<=n;++i)
            {
                if((o>>(i-1))&1)
                {
                    z+=a[i];
                    ++cnt;
                    mx=max(mx,a[i]);
                }
            }
            if(cnt>=3&&z>mx*2)
            {
                ++ans;
                ans%=mod;
            }
        }
        printf("%lld\n",ans);
        return 0;
    }
    else if(is1)
    {
        for(int i=3;i<=n;++i)
        {
            ans+=C(n,i);
            ans%=mod;
        }
        printf("%lld\n",ans);
        return 0; 
    }
    else
    {
        sort(a.begin()+1,a.end());
        for(int i=3;i<=n;++i)
        {
            for(int j=i;j<=n;++j)
            {
                
            }
        }
    }
    return 0;
}