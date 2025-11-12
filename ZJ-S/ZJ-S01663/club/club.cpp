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
cint N=1e5;
int n,a[3][N+1];
int mxp[N+1],cnt[3];
int spc;
ll ans;
vector<int>delt;
void solve()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        for(int c=0;c<3;++c)
        {
            a[c][i]=read();
        }
    }
    cnt[0]=cnt[1]=cnt[2]=0;
    ans=0;
    for(int i=1;i<=n;++i)
    {
        for(int c=0;c<3;++c)
        {
            if(a[c][i]>a[mxp[i]][i])mxp[i]=c;
        }
        ++cnt[mxp[i]];
        ans+=a[mxp[i]][i];
    }
    spc=-1;
    for(int c=0;c<3;++c)if(cnt[c]>(n>>1))spc=c;
    if(spc==-1)
    {
        princh(ans,'\n');
        return;
    }
    delt.clear();
    for(int i=1;i<=n;++i)
    {
        if(mxp[i]==spc)
        {
            int mx=0;
            for(int c=0;c<3;++c)
            {
                if(c!=spc)mx=max(mx,a[c][i]);
            }
            delt.push_back(a[spc][i]-mx);
        }
    }
    sort(delt.begin(),delt.end());
    for(int i=0;i<cnt[spc]-(n>>1);++i)
    {
        ans-=delt[i];
    }
    princh(ans,'\n');
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}