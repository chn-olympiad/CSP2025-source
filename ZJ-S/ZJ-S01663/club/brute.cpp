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
int n,a[N+1],b[N+1],c[N+1];
ll dp[N+1][N+1][N+1];
ll ans;
void solve()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
        b[i]=read();
        c[i]=read();
    }
    for(int i=1;i<=n;++i)
    {
        for(int ca=n;ca>=0;--ca)
        {
            for(int cb=n;cb>=0;--cb)
            {
                if(ca+cb>i)continue;
                cint cc=i-ca-cb;
                dp[ca][cb][cc]=0;
                if(ca)dp[ca][cb][cc]=max(dp[ca][cb][cc],dp[ca-1][cb][cc]+a[i]);
                if(cb)dp[ca][cb][cc]=max(dp[ca][cb][cc],dp[ca][cb-1][cc]+b[i]);
                if(cc)dp[ca][cb][cc]=max(dp[ca][cb][cc],dp[ca][cb][cc-1]+c[i]);
            }
        }
    }
    ans=0;
    for(int ca=n;ca>=0;--ca)
    {
        for(int cb=n;cb>=0;--cb)
        {
            if(ca+cb>n)continue;
            cint cc=n-ca-cb;
            if(ca<=(n>>1)&&cb<=(n>>1)&&cc<=(n>>1))ans=max(ans,dp[ca][cb][cc]);
        }
    }
    princh(ans,'\n');
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("brute.out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}