#include<bits/stdc++.h>
using namespace std;
int a[10015][10015],dis[20005],vis[20005],b[15][10005],n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++)
	a[i][i]=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,len;
		cin>>u>>v>>len;
		a[u][v]=a[v][u]=len;
	}
	if(k==0)
	{
	long long ans=0;
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		int minn=1e9,it=0;
		for(int j=1;j<=n;j++)
		if(dis[j]<minn&&vis[j]==0)
		{
			minn=dis[j];
			it=j;
		}
		ans=ans+minn;
		vis[it]=1;
		for(int j=1;j<=n;j++)
		{
		dis[j]=min(dis[j],a[it][j]);
		}
	}
	cout<<ans;
	return 0;
	}
	for(int i=1;i<=k;i++)
	for(int j=0;j<=n;j++)
	cin>>b[i][j];
	int flag=1;
	for(int i=1;i<=k;i++)
	if(b[i][0]!=0)
	flag=0;
	if(flag==0)
	{
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		for(int h=1;h<=n;h++)
		{
		a[j][h]=min(a[j][h],b[i][0]+b[i][j]+b[i][h]);
		}
		for(int j=1;j<=n;j++)
		a[j][i+n]=a[i+n][j]=(b[i][0]+b[i][j]);
	}
	long long ans=0;
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		int minn=1e9,it=0;
		for(int j=1;j<=n;j++)
		if(dis[j]<minn&&vis[j]==0)
		{
			minn=dis[j];
			it=j;
		}
		ans=ans+minn;
		vis[it]=1;
		for(int j=1;j<=n+k;j++)
		{
		dis[j]=min(dis[j],a[it][j]);
		}
	}
	cout<<ans;
	return 0;
}

