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
cll inf=1e18;
int n,m,k;
struct edge{
    int u,v,val;
}e[M+1];
vector<edge>E;
int f[N+1];
ll ans,sum;
int find(cint u)
{
    return (f[u]==u?u:(f[u]=find(f[u])));
}
void merge(int u,int v,cint val)
{
    u=find(u);
    v=find(v);
    if(u==v)return;
    f[u]=v;
    sum+=val;
}
void kruskal()
{
    for(int i=1;i<=n+k;++i)
    {
        f[i]=i;
    }
    sum=0;
    sort(E.begin(),E.end(),[&](edge x,edge y){return x.val<y.val;});
    for(edge e:E)merge(e.u,e.v,e.val);
}
bool flag[K+1];
int a[K+1][N+1];
int c[K+1];
void calc()
{
    E.clear();
    for(int i=1;i<=m;++i)E.push_back(e[i]);
    for(int i=1;i<=k;++i)
    {
        if(flag[i])
        {
            for(int p=1;p<=n;++p)
            {
                E.push_back({i+n,p,a[i][p]});
            }
        }
    }
    kruskal();
    for(int i=1;i<=k;++i)if(flag[i])sum+=c[i];
    ans=min(ans,sum);
}
void dfs(cint now)
{
    if(now>k)
    {
        calc();
        return;
    }
    flag[now]=1;
    dfs(now+1);
    flag[now]=0;
    dfs(now+1);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("brute.out","w",stdout);
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=m;++i)
    {
        e[i].u=read();
        e[i].v=read();
        e[i].val=read();
    }
    for(int i=1;i<=k;++i)
    {
        c[i]=read();
        for(int p=1;p<=n;++p)
        {
            a[i][p]=read();
        }
    }
    ans=inf;
    dfs(1);
    print(ans);
    return 0;
}