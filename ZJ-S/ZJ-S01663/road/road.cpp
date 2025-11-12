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
cint N=1e4+10,M=1e6,K=10;
cint inf=1e9+1;
int n,m,k;
int c[K+1];
struct edge{
    int u,v,val;
    int id;
}e[M+1];
vector<edge>used;
int f[N+1],siz[N+1];
int find(cint u)
{
    return (f[u]==u?u:(f[u]=find(f[u])));
}
ll ans,sum;
inline bool merge(int u,int v,cint val)
{
    u=find(u),v=find(v);
    if(u==v)return 0;
    if(siz[u]>siz[v])swap(u,v);
    sum+=val;
    siz[v]+=siz[u];
    f[u]=v;
    return 1;
}
bool flag[K+1];
void calc()
{
    sum=0;
    for(int i=1;i<=k;++i)if(flag[i])sum+=c[i];
    for(int i=1;i<=n+k;++i)f[i]=i,siz[i]=1;
    for(int i=1;i<=m;++i)
    {
        if(flag[e[i].id])
        {
            merge(e[i].u,e[i].v,e[i].val);
        }
    }
    // for(int i=1;i<=k;++i)putchar('0'+flag[i]);
    // putchar(':');
    // princh(sum,'\n');
    ans=min(ans,sum);
}
void dfs(cint now)
{
    if(now>k)
    {
        calc();
        return;
    }
    flag[now]=0;
    dfs(now+1);
    flag[now]=1;
    dfs(now+1);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=m;++i)
    {
        e[i].u=read();
        e[i].v=read();
        e[i].val=read();
    }
    sort(e+1,e+m+1,[&](edge x,edge y){return x.val<y.val;});
    for(int i=1;i<=n;++i)f[i]=i,siz[i]=1;
    for(int i=1;i<=m;++i)
    {
        if(merge(e[i].u,e[i].v,e[i].val))
        {
            used.push_back(e[i]);
        }
    }
    m=n-1;
    for(int i=1;i<=m;++i)
    {
        e[i]=used[i-1];
    }
    ans=sum;
    for(int i=1;i<=k;++i)
    {
        c[i]=read();
        for(int p=1;p<=n;++p)
        {
            e[++m]={n+i,p,read(),i};
        }
    }
    sort(e+1,e+m+1,[&](edge x,edge y){return x.val<y.val;});
    flag[0]=1;
    dfs(1);
    print(ans);
    return 0;
}