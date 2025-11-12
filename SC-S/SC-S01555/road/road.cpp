#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k,f[20001],h[20001],c[21],ans=1e18;
vector<tuple<int,int,int>>edge1,edge;

int find(int i)
{return(i==f[i])?i:(f[i]=find(f[i]));}
void merge(int u,int v)
{
    int fu=find(u),fv=find(v);
    if(h[fu]<h[fv])
        swap(fu,fv);
    f[fv]=fu;
    h[fu]+=h[fu]==h[fv];
}

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge1.push_back({w,u,v});
    }
    for(int i=1;i<=n;i++)
        f[i]=i;
    sort(edge1.begin(),edge1.end());
    for(auto&[w,u,v]:edge1)
        if(find(u)!=find(v))
            f[f[u]]=f[v],
            edge.push_back({w,u,v});
    for(int i=0;i<k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            int w=0;
            cin>>w;
            edge.push_back({w,i+n+1,j});
        }
    }
    sort(edge.begin(),edge.end());
    for(int i=0;i<1<<k;i++)
    {
        int now=0;
        for(int j=0;j<k;j++)
            if((i>>j)&1)
                now+=c[j];
        for(int j=1;j<=n+k;j++)
            f[j]=j,
            h[j]=1;
        for(auto&[w,u,v]:edge)
            if(((u<=n)||((i>>u-n-1)&1))&&(find(u)!=find(v)))
                now+=w,
                merge(u,v);
        ans=min(ans,now);
    }
    cout<<ans<<"\n";
}