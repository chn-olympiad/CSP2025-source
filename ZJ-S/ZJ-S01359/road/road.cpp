#include<bits/stdc++.h>
using namespace std;
int n,m,k,dis[10005],vec[10005][10005],tt;
long long int ans,a[10005];
bool vis[10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    memset(vec,-1,sizeof vec);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        long long int w;
        cin>>u>>v>>w;
        vec[u][v]=min((vec[u][v]==-1?LLONG_MAX:vec[u][v]),w);
        vec[v][u]=min((vec[v][u]==-1?LLONG_MAX:vec[v][u]),w);
    }
    for(int i=1;i<=k;i++)
    {
        long long int c;
        cin>>c;
        for(int j=1;j<=n;j++)
            cin>>a[j];
        for(int j=1;j<n;j++)
            for(int l=j+1;l<=n;l++)
            {
                vec[j][l]=min((vec[j][l]==-1?LLONG_MAX:vec[j][l]),c+a[j]+a[l]);
                vec[l][j]=min((vec[l][j]==-1?LLONG_MAX:vec[l][j]),c+a[j]+a[l]);
            }
    }
    for(int i=1;i<=n;i++)
        dis[i]=INT_MAX;
    for(int i=1;i<=n;i++)
        dis[i]=vec[1][i];
    vis[1]=true;
    tt=1;
    while(tt<n)
    {
        long long int miii=0;
        for(int i=1;i<=n;i++)
            if(vis[i]==false)
            {
                if(miii==0 || dis[miii]>=dis[i])
                    miii=i;
            }
        ans+=dis[miii];
        tt++;
        vis[miii]=true;
        for(int i=1;i<=n;i++)
            dis[i]=min(dis[i],vec[miii][i]);
    }
    cout<<ans<<"\n";
	return 0;
}