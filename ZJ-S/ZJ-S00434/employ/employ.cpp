#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e4+10;
constexpr int maxm=7e6+10;
constexpr int INF=LLONG_MAX/2;
constexpr int mod=998244353;

int n,m;
char s[maxn];
int a[maxn];
int flag1=1;
int cnt;
int jc[maxn];
int ny[maxn];
int nyy[maxn];
int ans;
int awa[maxn];

int check()
{
    int have=0;
    int si=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(awa[j]==i)
            {
                if(s[i]=='1'&&si<a[j])
                {
                    ++have;
                }
                else
                {
                    ++si;
                }
                break;
            }
        }
    }
    return have>=m;
}


void dfs(int step)
{
    if(step==n+1)
    {
        if(check()) ++ans;
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(!awa[i])
        {
            awa[i]=step;
            dfs(step+1);
            awa[i]=0;
        }
    }
}


signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    jc[1]=1;
    ny[1]=1;
    nyy[1]=1;
    for(int i=2;i<=600;++i)
    {
        jc[i]=jc[i-1]*i%mod;
        ny[i]=ny[mod%i]*(mod-mod/i)%mod;
        nyy[i]=nyy[i-1]*ny[i]%mod;
    }
    scanf("%lld%lld",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        cnt+=a[i];
    }

    if(n<=18)
    {
        dfs(1);
        printf("%lld",ans);
        return 0;
    }

    for(int i=m;i<=cnt;++i)
    {
        ans+=jc[cnt]*nyy[cnt-m]%mod*(n-cnt)%mod*nyy[n-m-1]%mod;
        ans%=mod;
    }
    printf("%lld",ans);
    return 0;
}
