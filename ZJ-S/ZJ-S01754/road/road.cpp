#include <iostream>
#include <algorithm>
#include <cstring>

#define int long long

using std::cin;
using std::min;
using std::sort;
using std::cout;

int n,m,k,ans,p;
int fa[10050];
int getfa(int x)
{
    if(x==fa[x])return x;
    return fa[x]=getfa(fa[x]);
}

struct edge
{
    edge() {}
    edge(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator<(edge b)const
    {
        return w<b.w;
    }
    int u,v,w;
} e[2000010];


signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    int cnt=m;
    for(int i=1; i<=k; i++)
    {
        int c,w;
        cin>>c;
        for(int j=1; j<=n; j++)
        {
            cin>>w;
            e[++cnt]=edge(j,n+i,w);
        }
    }
    sort(e+1,e+cnt+1);
    for(int i=1; i<=n+k; i++)
    {
        fa[i]=i;
    }
    for(int i=1; i<=cnt; i++)
    {
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int fu=getfa(u),fv=getfa(v);
        if(fu!=fv)
        {
            fa[fu]=fv;
            ans+=w;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
