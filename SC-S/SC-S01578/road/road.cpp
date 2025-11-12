#include<bits/stdc++.h>
using namespace std;
long long n,m,a[20][1010],c[20],tot,k,vis[1010],ans;
queue<long long> q;
long long head[1000010],gto[1000010],nxt[1000010],edge[1000010];
void add(long long u,long long v,long long w)
{
	tot++;
	nxt[tot]=head[u];
	gto[tot]=v;
	edge[tot]=w;
	head[u]=tot;
}
void dfs(long long rt,long long cst,long long cnt)
{
	if(cnt==n)
	{
//		cout<<cst<<endl;
		ans=min(ans,cst);
	}
	for(int i=head[rt];i!=0;i=nxt[i])
	{
//		cout<<gto[i]<<endl;
		if(vis[gto[i]]==1)
		{
//			cout<<"amnos"<<endl;
			continue;
		}
		vis[gto[i]]=1;
		dfs(gto[i],cst+edge[i],cnt+1);
		dfs(rt,cst+edge[i],cnt+1);
		vis[gto[i]]=0;
	}
	for(int i=1;i<=k;i++)
	{
		if(c[i]<ans)
		{
			for(int j=1;j<=n;j++)
			{
				if(vis[j]==1)
				{
					continue;
				}
				vis[j]=1;
				dfs(j,cst+a[i][j]+a[i][rt]+c[i],cnt+1);
				dfs(rt,cst+a[i][j]+a[i][rt]+c[i],cnt+1);
				vis[j]=0;
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ans=100000000000010;
	memset(vis,0,sizeof(vis));
	cin>>n>>m>>k;
	long long u,v,g;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>g;
		add(u,v,g);
		add(v,u,g);
	}
//	cout<<"nxt"<<endl;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	vis[1]=1;
	dfs(1,0,1);
	cout<<ans<<endl;
	return 0;
}
