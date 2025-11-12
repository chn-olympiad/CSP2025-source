#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn = 5e2+10;
constexpr int maxm = 2e6+10;
constexpr int mod = 998244353;
// bool Mst;

int n,m;
char s[maxn];
int ci[maxn];

int fac[maxn];

void init()
{
    fac[0]=fac[1]=1;
    for(int i=2;i<=500;++i)
    {
        fac[i]=fac[i-1]*i%mod;
    }
}

void sub1()
{
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        if(ci[i]==0)
        {
            ++cnt;
        }
    }
    if(n-cnt<m)
    {
        printf("0");
        return;
    }
    printf("%lld\n",fac[n]);
}

int ans2,cnt;
bool vis[maxn];

void dfs(int dep,int cnt0)
{
    if(dep>n)
    {
        if(cnt>=m)
        {
            ++ans2;
            if(ans2>=mod)
            {
                ans2-=mod;
            }
        }
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
        {
            vis[i]=1;
            if(ci[i]<=cnt0 || s[dep]=='0')
            {
                dfs(dep+1,cnt0+1);
            }
            else
            {
                ++cnt;
                dfs(dep+1,0);
                --cnt;
            }
            vis[i]=0;
        }
    }
}

void sub2()
{
    dfs(1,0);
    printf("%lld",ans2);
}

// bool Med;
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    // cerr<<1.0*(&Med-&Mst)/1024/1024<<" M\n";

    init();

    scanf("%lld%lld",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",ci+i);
    }

    bool flag1=1;
    for(int i=1;s[i];++i)
    {
        if(s[i]=='0')
        {
            flag1=0;
            break;
        }
    }

    if(flag1)
    {
        sub1();
        return 0;
    }

    if(n<=10)
    {
        sub2();
        return 0;
    }


    return 0;
}
