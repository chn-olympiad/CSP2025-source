#include<bits/stdc++.h>
using namespace std;

int n,m,k,c[15],l[15][10005];
long long ans;
bool vis[1000005];
struct node
{
    int u;
    int v;
    int w;
}a[1000005];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
void xl0()
{
    for(int i=1;i<=m;i++)
    {
        if(a[i].u!=a[i].v&&(vis[a[i].u]==0||vis[a[i].v]==0))
        {
            ans+=a[i].w;
            vis[a[i].u]=1;
            vis[a[i].v]=1;
        }
    }
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>l[i][j];
        }
    }
    if(k==0)
    {
        sort(a+1,a+m+1,cmp);
        xl0();
        cout<<ans;
    }

    return 0;
}