#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn = 1e4+10;
constexpr int maxm = 2e6+10;
// bool Mst;


typedef struct edge
{
    int x,y,w;
    bool operator<(const edge &o)const
    {
        return w<o.w;
    }
}edge;

int n,m,k;
edge edges[maxm];
int ci[20];
signed mp[maxn][maxn];
int wi[maxn];

int fa[maxn];

int finr(int x)
{
    return fa[x]==x ? x : fa[x]=finr(fa[x]);
}

void sub1()
{
    sort(edges+1,edges+1+m);
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
    }
    int tal=0;
    int cnt=0;

    for(int i=1;i<=m;++i)
    {
        int xr=finr(edges[i].x);
        int yr=finr(edges[i].y);
        if(xr!=yr)
        {
            tal+=edges[i].w;
            fa[xr]=yr;
            ++cnt;
        }
        if(cnt==n-1)
        {
            break;
        }
    }
    printf("%lld",tal);
}

int idx;

bool vis[maxn];
void sub2()
{
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
    }
    int tal=0;
    int cnt=0;

    for(int i=1;i<=idx;++i)
    {
        int xr=finr(edges[i].x);
        int yr=finr(edges[i].y);
        if(xr!=yr)
        {
            tal+=edges[i].w;
            fa[xr]=yr;
            ++cnt;
        }
        if(cnt==n-1)
        {
            break;
        }
    }
    printf("%lld",tal);
}

// bool Med;
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    // cerr<<1.0*(&Med-&Mst)/1024/1024<<" M\n";

    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;++i)
    {
        scanf("%lld%lld%lld",&edges[i].x,&edges[i].y,&edges[i].w);
    }
    if(k==0)
    {
        sub1();
        return 0;
    }

    bool flaga=1;
    idx=m;
    int id=n;
    for(int i=1;i<=k;++i)
    {
        scanf("%lld",ci+i);
        // bool use=0;
        int id2=++id;
        if(ci[i])
        {
            flaga=0;
        }
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&wi[i]);
            if(wi[i]==0)
            {
                id2=i;
            }
        }
        for(int i=1;i<=n;++i)
        {
            edges[++idx].x=id2;
            edges[idx].y=i;
            edges[idx].w=wi[i];
        }
    }

    if(flaga)
    {
        sort(edges+1,edges+1+idx);
        sub2();
        return 0;
    }

    return 0;
}
