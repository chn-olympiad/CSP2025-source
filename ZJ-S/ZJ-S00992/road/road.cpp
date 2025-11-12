#include<bits/stdc++.h>
using namespace std;
int n,m,k,t;
struct Edge
{
    int u,v,w;
}e[1000010],g[1000010];
int c[20];
int fa[1000010];
int h[1000010];
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
long long ans=1145141919810975123ll;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    for(int i=1;i<=n;i++) fa[i]=i,h[i]=0;
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int u=find(e[i].u),v=find(e[i].v);
        if(u==v) continue;
        if(h[u]<h[v]) swap(u,v);
        g[++t]=e[i],fa[v]=u,h[u]+=(h[u]==h[v]);
    }
    m=t;
    for(int i=1;i<=m;i++) e[i]=g[i];
    for(int now=1;now<=k;now++)
    {
        scanf("%d",&c[now]);
        for(int i=1;i<=n;i++)
        {
            m++,e[m].u=i,e[m].v=n+now;
            scanf("%d",&e[m].w);
        }
    }
    sort(e+1,e+m+1,cmp);
    for(int s=0;s<(1<<k);s++)
    {
        long long nowans=0;
        for(int i=1;i<=k;i++) if(s>>(i-1)&1) nowans+=c[i];
        for(int i=1;i<=n+k;i++) fa[i]=i,h[i]=0;
        for(int i=1;i<=m;i++)
        {
            int u=find(e[i].u),v=find(e[i].v);
            if(u==v) continue;
            if(v>n&&!(s>>(v-n-1)&1)) continue;
            if(h[u]<h[v]) swap(u,v);
            nowans+=e[i].w,fa[v]=u,h[u]+=(h[u]==h[v]);
        }
        ans=min(ans,nowans);
    }
    printf("%lld\n",ans);
    // cerr<<clock()<<endl;
    return 0;
}