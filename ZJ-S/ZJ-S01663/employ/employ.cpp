#include<bits/stdc++.h>
#define cint const int
#define uint unsigned int
#define cuint const unsigned int
#define ll long long
#define cll const long long
#define ull const unsigned long long
#define cull const unsigned long long
using namespace std;
ll read()
{
    ll x=0;
    bool zf=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')zf=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch-'0');
        ch=getchar();
    }
    return x;
}
void print(cll x)
{
    if(x<0)
    {
        putchar('-');
        print(-x);
        return;
    }
    if(x<10)
    {
        putchar(x+'0');
        return;
    }
    print(x/10);
    putchar(x%10+'0');
}
void princh(cll x,const char ch)
{
    print(x);
    putchar(ch);
}
cint N=500;
cint mod=998244353;
int n,m;
int cnt[N<<1|1];
bool a[N+1];
int s[N+1];
void input()
{
    char ch=getchar();
    while(ch!='0'&&ch!='1')ch=getchar();
    for(int i=1;i<=n;++i)
    {
        a[i]=ch-'0';
        ch=getchar();
    }
}
int fac[N+1];
int f[N+1][N+1],g[N+1][N+1];
void DP()
{
    f[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            for(int k=0;k<=n;++k)
            {
                g[j][k]=f[j][k];
            }
        }
        for(int j=0;j<=n;++j)
        {
            for(int k=0;k<=n;++k)
            {
                if(!a[i])continue;
                if(j)
                {
                    f[j][k]=(f[j][k]+1ll*g[j-1][k]*max(0,cnt[i-s[i]+j-1]-(j-1)-k))%mod;
                }
                if(k)
                {
                    f[j][k]=(f[j][k]+1ll*g[j][k-1]*max(0,cnt[i-s[i]+j]-j-(k-1)))%mod;
                }
            }
        }
    }
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            f[i][j]=1ll*f[i][j]*fac[n-i-j]%mod;
        }
    }
}
int ans;
int res[N+1];
void calc()
{
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            res[i]=(res[i]+1ll*((j&1)?mod-1:1)*f[i][j])%mod;
        }
    }
    for(int i=m;i<=s[n];++i)
    {
        (ans+=res[s[n]-i])>=mod?(ans-=mod):0;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read();
    m=read();
    input();
    for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;++i)++cnt[read()];
    fac[0]=1;
    for(int i=1;i<=n;++i)fac[i]=1ll*i*fac[i-1]%mod;
    for(int i=1;i<=(n<<1);++i)cnt[i]+=cnt[i-1];
    DP();
    calc();
    print(ans);
    return 0;
}