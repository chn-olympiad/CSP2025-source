#include<bits/stdc++.h>
#define int long long
using namespace std;

static constexpr const int Mod=998244353;
int n,m,q,s[501],c[501],a[501],ans[501],cnt[501],pre[501],f[501][501],g[501],fac[501],inv[501],now;

int calc()
{
    int now=0,tot=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i])
        {
            if(tot>=c[a[i]])
                ++tot;
            else
                ++now;
        }
        else
            ++tot;
    }
    return now;
}

void dfs(int u)
{
    if(u>n)
    {
        ans[calc()]++;
        return;
    }
    for(int i=u;i<=n;i++)
        swap(a[i],a[u]),
        dfs(u+1),
        swap(a[i],a[u]);
}

int Pow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
            (ans*=a)%=Mod;
        (a*=a)%=Mod;
        b>>=1;
    }
    return ans;
}

int C(int n,int m)
{return fac[n]*inv[m]%Mod*inv[n-m]%Mod;}

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        s[i]=c-'0';
        if(s[i])
            pre[++m]=now;
        else
            ++now;
    }
    for(int i=1;i<=n;i++)
        cin>>c[i],
        ++cnt[c[i]],
        a[i]=i;
    if(n<=10)
    {
        dfs(1);
        int num=0;
        for(int i=q;i<=n;i++)
            num+=ans[i];
        cout<<num<<"\n";
        return 0;
    }
    for(int i=1;i<=n;i++)
        cnt[i]+=cnt[i-1];
    f[0][0]=1;
    for(int i=0;i<m;i++)
        for(int j=0;j<=i;j++)
        {
            int coeff=cnt[pre[i+1]+j]-j;
            (f[i+1][j+1]+=coeff*f[i][j])%=Mod;
            (f[i+1][j]+=f[i][j])%=Mod;
        }
    fac[0]=inv[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%Mod,
        inv[i]=Pow(fac[i],Mod-2);
    int ans=0;
    for(int i=0;i<=m-q;i++)
        ans+=f[m][i];
    cout<<ans%Mod<<"\n";
}