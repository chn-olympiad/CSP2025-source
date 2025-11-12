#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e4+10;
constexpr int maxm=2e6+10;
constexpr int INF=LONG_LONG_MAX/2;
int n,m,k;
//typedef struct edge
//{
//    int to,nxt,w;
//}edge;
//edge edges[maxm];
//int heads[maxn];
//int enums;
//void add_edges(int x,int y,int w)
//{
//    ++enums;
//    edges[enums].to=y;
//    edges[enums].w=w;
//    edges[enums].nxt=heads[x];
//    heads[x]=enums;
//}
typedef struct node
{
    int x,y,w;
    bool operator<(const node &a)const
    {
        return w>a.w;
    }
} node;
priority_queue<node> edges;
int fa[maxn];
int hei[maxn];
int a[maxn];
int e[maxn][maxn];
void init()
{
    for(int i=1; i<=n; ++i)
    {
        fa[i]=i;
    }
}
int find_root(int x)
{
    int r=x;
    while(r!=fa[x])
    {
        r=fa[x];
    }
    for(int i=x,j=fa[i]; fa[i]!=r; i=j)
    {
        j=fa[i];
        fa[i]=r;
    }
    return r;
}
void join(int x,int y)
{
    int xr=find_root(x);
    int yr=find_root(y);
    if(hei[xr]==hei[yr])
    {
        fa[xr]=yr;
        ++hei[yr];
    }
    else if(hei[xr]<hei[yr])
    {
        fa[xr]=yr;
    }
    else
    {
        fa[yr]=xr;
    }
}
int mst()
{
    int cnt=0;
    int sum=0;
    while(1)
    {
        auto no=edges.top();
        edges.pop();
        int x=no.x;
        int y=no.y;
        int w=no.w;
        if(find_root(x)!=find_root(y))
        {
            join(x,y);
            //cout<<x<<' '<<y<<' '<<w<<endl;
            ++cnt;
            sum+=w;
            if(cnt==n-1)
            {
                break;
            }
        }
    }
    return sum;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1; i<=m; ++i)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        edges.push({u,v,w});
//        add_edges(u,v,w);
//        add_edges(v,u,w);
    }

    for(int i=1; i<=k; ++i)
    {
        int c;
        scanf("%lld",&c);
        for(int j=1; j<=n; ++j)
        {
            scanf("%lld",a+j);
        }
    }
    init();
    int ans=mst();
    printf("%lld",ans);
    return 0;
}

