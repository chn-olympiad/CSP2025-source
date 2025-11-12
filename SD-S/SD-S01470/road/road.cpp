#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=0x3f3f3f3f3f3f3f3f,d[10015];
bool f[10015];
bool s[10015];
long long c[15],a[15][10005];
long long mc,mai;
vector<pair<long long,long long> >z[10015],g[10015];
long long prim()
{
	long long res=0;
	memset(d,0x3f,sizeof(d));
	//for(int i=1;i<=n;i++)cout<<d[i]<<'\n';
	memset(f,0,sizeof(f));
	d[1]=0;
	for(int i=1;i<=n;i++)
	{
		long long u=0;
		for(int i=1;i<=n;i++)
		{
			if(d[i]<d[u]&&(!f[i]))u=i;
		}
		f[u]=1;
		res+=d[u];
		for(int i=0;i<z[u].size();i++)
		{
			long long v=z[u][i].first,w=z[u][i].second;
			if(f[v])continue;
			d[v]=min(d[v],d[u]+w);
		}
	}
	return res;
}
void dfs(long long now)
{
	if(now>0)
	{
		memcpy(g,z,sizeof(z));
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long w=0x3f3f3f3f3f3f3f3f;
				for(int h=1;h<=k;h++)if(s[h])w=min(w,a[h][i]+a[h][j]);
				g[i].push_back({j,w});
				g[j].push_back({i,w});
			}
		}
		long long sumc=0;
		for(int i=1;i<=k;i++)if(s[i])sumc+=c[i];
		ans=min(ans,prim());
		for(int i=1;i<=n;i++)g[i].clear();
		return;
	}
	s[now]=1;
	dfs(now+1);
	s[now]=0;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		z[u].push_back({v,w});
		z[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		mc=max(mc,c[i]);
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(mc==0)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long w=0x3f3f3f3f3f3f3f3f;
				for(int h=1;h<=k;h++)w=min(w,a[h][i]+a[h][j]);
				z[i].push_back({j,w});
				z[j].push_back({i,w});
			}
		}
		cout<<prim();
		return 0;
	}
	dfs(1);
	cout<<ans<<'\n';
	cout<<prim();
	return 0;
}
