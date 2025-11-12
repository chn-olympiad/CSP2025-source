#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int Maxn=1e4+20,Maxm=1e6+10;
int n,m,k,cnt=0;
LL ans=0;
LL c[Maxn],a[15][Maxn],fa[Maxn];
struct Edge
{
    int u,v;
    LL w;
}e[Maxm];
bool cmp(Edge x,Edge y)
{
    return x.w<y.w;
}
int Find(int x)
{
    if(fa[x]==x) return fa[x];
    return fa[x]=Find(fa[x]);
}
void kruskal()
{
    for(int i=1;i<=m;i++)
    {
        int u=e[i].u,v=e[i].v;
        int fu=Find(u),fv=Find(v);
        if(fu==fv) continue;
        LL mind=1e18;
        int minj=-1;
        for(int j=1;j<=k;j++)
        {
            if(a[j][fu]+a[j][fv]+c[j]<mind)
            {
                mind=a[j][fu]+a[j][fv]+c[j];
                minj=j;
            }
        }
        fa[fu]=fv;
        cnt+=1;
        if(mind<=e[i].w)
        {
            ans+=mind;
            c[minj]=0;
        }
        else ans+=e[i].w;
        for(int j=1;j<=k;j++) a[j][fv]=min(a[j][fu],a[j][fv]);
        if(cnt>=n-1) break;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    sort(e+1,e+1+m,cmp);
    kruskal();
    printf("%lld\n",ans);
    return 0;
}
