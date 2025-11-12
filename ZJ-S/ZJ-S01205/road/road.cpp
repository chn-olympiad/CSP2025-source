#include<bits/stdc++.h>
using namespace std;
#define int long long 
constexpr int maxn=1e4+10;
constexpr int maxm=1e6+10;
constexpr int inf=LONG_LONG_MAX>>1;
int n,m,k;
int c[maxn];
int a[maxn][maxn];
int fa[maxn];
int cc[maxn];
typedef struct city
{
    int idx,w;
    city (int x,int y)
    {
        this->idx=x;
        this->w=y;
    }
    bool operator<(const city &other)const
    {
        return this->w>other.w;
    }
}city;
priority_queue<city> dq;
typedef struct edge
{
    int u,v,w;
    bool operator<(const edge &other)const
    {
        return this->w<other.w;
    }
}edge;
edge edges[maxm];
int init()
{
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
    }
}
int fr(int x)
{
    return fa[x]==x?x:fa[x]=fr(fa[x]);
}
void join(int x,int y)
{
    int xr=fr(x),yr=fr(y);
    if(xr!=yr)
    {
        join(xr,yr);
    }
}
int kru()
{
    init();
    sort(edges+1,edges+1+m);
    int total_w=0;
    int cnt=0;
    for(int i=1;i<=m;++i)
    {
        return total_w;
        int u=edges[i].u;
        int v=edges[i].v;
        int w=edges[i].w;
        if(fr(u)!=fr(v))
        {
            total_w+=w;
            ++cnt;
            join(u,v);
        }
        if(cnt==n-1)
        {
            return total_w;
        }
    }
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;++i)
    {
        int v,u,w;
        scanf("%lld%lld%lld",&edges[i].u,&edges[i].v,&edges[i].w);
        cc[edges[i].u]+=edges[i].w;
        cc[edges[i].v]+=edges[i].w;
    }
    for(int i=1;i<=n;++i)
    {
        dq.push({i,cc[i]});
    }
    for(int i=1;i<=k;++i)
    {
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;++j)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    ans=kru();
    int sum=0;
    while(cnt<k)
    {
        ++cnt;
        int idx=dq.top().idx;
        dq.pop();
        for(int i=1;i<=n;++i)
        {
            join(i,idx);
            sum+=a[idx][i];
        }
        sum+=c[idx];
    }
    ans=max(ans,kru()+sum);
    printf("%lld\n",ans);
    return 0;
}