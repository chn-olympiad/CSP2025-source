#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e7+10;
int fa[maxn];
int wi[maxn];
typedef struct edge
{
    int x,y,z;
    bool operator<(const edge& o)const
    {
        return z<o.z;
    }
}edge;
edge edges[maxn];
void init(int n)
{
    for(int i=1; i<=n; ++i)
    {
        fa[i]=i;
    }
}
int fr(int x)
{
    int r=x;
    while(r!=fa[r])
    {
        r=fa[r];
    }
    for(int i=x,j=fa[i]; i!=r; i=j)
    {
        j=fa[i];
        fa[i]=r;
    }
    return r;
}
void join(int x,int y)
{
    int xr=fr(x),yr=fr(y);
    if(xr!=yr)
    {
        fa[xr]=yr;
    }
}
int kru(int n,int m)
{
    init(n);
    sort(edges+1,edges+1+m);
    int total_wei=0;
    int edges_cnt=0;
    for(int i=1; i<=m; ++i)
    {
        int u=edges[i].x;
        int v=edges[i].y;
        int w=edges[i].z;
        if(fr(u)!=fr(v))
        {
            join(u,v);
            total_wei+=w;
            edges_cnt+=1;
            if(edges_cnt==n-1)
            {
                return total_wei;
            }
        }
    }
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1; i<=m; ++i)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&edges[i].x,&edges[i].y,&edges[i].z);
    }
    int sta=m;
    for(int i=1; i<=k; ++i)
    {
        int c;
        scanf("%lld",&c);
        for(int j=1; j<=n; ++j)
        {
            scanf("%lld",&wi[j]);
        }
        for(int j=1; j<=n; ++j)
        {
            for(int k=1; k<=n; ++k)
            {
                if(j==k) continue;
                edges[++sta].x=j;
                edges[sta].y=k;
                edges[sta].z=wi[j]+wi[k]+c;
            }
        }
    }
    int ans=kru(n,sta);
    printf("%lld\n",ans);


    return 0;
}