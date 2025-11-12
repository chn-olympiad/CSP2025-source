#include<bits/stdc++.h>
using namespace std;
int n,m,k,minn=1e9;
struct node
{
	int u,v,w;
}a[10005];
int f[10],b[10][10005];
bool vis[10005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			return 0;
		}
	}
	return 1;
}
void dfs(int step,int pay)
{
	
	if(step>m)
	{
		if(check())
		{
			minn=min(minn,pay);
		}
		
		return;
	}
	
	bool f1=0,f2=0;
	if(vis[a[step].u]==0)
	{
		f1=1;
	}
	if(vis[a[step].u]==0)
	{
		f2=1;
	}
	vis[a[step].u]=1;
	vis[a[step].v]=1;dfs(step+1,pay+a[step].w);
	if(f1)vis[a[step].u]=0;
	if(f2)vis[a[step].v]=0;
	dfs(step+1,pay);
	
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
		cin>>f[i];
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
		}
	}
	sort(a+1,a+n+1,cmp);

	dfs(1,0);
	cout<<minn;
	return 0;
}