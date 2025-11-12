#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
int c[15],a[15][10005],fa[10000005],vis[10000005];
struct node
{
    int u,v,w,id;
}edge[10000005];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        edge[i]={x,y,z,0};
    }
    int pos=m+1;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            edge[pos++]={n+pos-1,j,c[i]+a[i][j],1};
        }
    }
    sort(edge+1,edge+m+n*k+1,cmp);
    int cnt=0,cnt2=0;//cnt->edge,cnt2->point
    for(int i=1;i<=m+n*k;i++)
    {
        int u1=find(edge[i].u),v1=find(edge[i].v);
        if(u1!=v1)
        {
            ans+=edge[i].w;
            cnt++;
            fa[u1]=v1;
            if(edge[i].id==1)
            {
                if(!vis[edge[i].u])
                {
                    vis[edge[i].u]=1;
                    cnt2++;
                }
            }
        }
        if(cnt==n-1)
        {
            cout<<ans;
            return 0;
        }
    }
    return 0;
}
