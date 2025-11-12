#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int ptc=1e4+50;
vector<pii>g[ptc];
int v[ptc];
bool vis[ptc];
int kc[ptc];
int kv[15][ptc];
int n,m,k;
void guess()
{
    for(int i=1;i<=k;i++)
    {
        scanf("%d",kc+i+n);
        for(int j=1;j<=n;j++)
        {
            int w;
            scanf("%d",&w);
            g[i+n].push_back({j,w});
            g[j].push_back({i+n,w});
        }
    }
    vis[1]=1;
    long long ans=0;
    for(auto x:g[1])
    {
        v[x.first]=min(v[x.first],kc[x.first]+x.second);
    }
    for(int i=2;i<=n+k;i++)
    {
        int p=2;
        for(int j=3;j<=n+k;j++)
        {
            if(vis[j])continue;
            if(vis[p]||v[j]<v[p])p=j;
        }
        ans+=v[p];
        vis[p]=1;
        for(auto x:g[p])
        {
            v[x.first]=min(v[x.first],kc[x.first]+x.second);
        }
    }
    printf("%lld",ans);
}
vector<pii> gb[ptc];
void onetime(int mask)
{

}
void bf()
{
    for(int i=0;i<n;i++)
    {

    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    memset(v,0x3f,sizeof(v));
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    if(n*n*(1<<k)<1e8)guess();
    else guess();
    return 0;
}
