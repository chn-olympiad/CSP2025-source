#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15;
int n,m,k,a[15][N],c[15],flag[N];
long long ans,now;
struct edge{int u,v,w;};
vector<edge> E,G;
int link[N];
int find(int u)
{
    return link[u]==u?u:(link[u]=find(link[u]));
}
bool cmp(edge a,edge b)
{
    return a.w<b.w; 
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) link[i]=i;
    for(int i=1,u,v,w;i<=m;i++)
    {
        cin>>u>>v>>w;
        E.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    sort(E.begin(),E.end(),cmp);
    for(int i=0,cnt=0;i<E.size();i++)
    {
        int u=E[i].u,v=E[i].v,w=E[i].w;
        u=find(u),v=find(v);
        if(u!=v)
        {
            cnt++;
            link[u]=v;
            ans+=w;
            G.push_back(E[i]);
            if(cnt==n-1) break;
        }
    }
    for(int i=1,total=0;i<(1<<k);i++)
    {
        now=total=0;
        E=G;
        for(int j=1;j<=k;j++)if((i>>(j-1))&1)
        {
            total++;
            now+=c[j];
            for(int l=1;l<=n;l++)
            {
                E.push_back({j+n,l,a[j][l]});
            }
        }
        for(int j=1;j<=n+k;j++) link[j]=j;
        sort(E.begin(),E.end(),cmp);
        for(int j=0,cnt=0;j<E.size();j++)
        {
            int u=E[j].u,v=E[j].v,w=E[j].w;
            u=find(u),v=find(v);
            if(u!=v)
            {
                cnt++;
                link[u]=v;
                now+=w;
                if(cnt==n+total-1) break;
            }
        }
        ans=min(ans,now);
        //cout<<i<<' '<<now<<endl;
    }
    cout<<ans<<'\n';
}