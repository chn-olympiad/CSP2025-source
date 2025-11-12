#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1e5+10;
int n,m,k;
struct edge
{
	int u,v,w;
}a[N<<1],e[N<<1];
int c[15],b[15][M],t[15],f[M];
bool cmp(edge p,edge q)
{
	return p.w<q.w;
}
int find(int x)
{
	return x==f[x] ? x : f[x]=find(f[x]);
}
void solve()
{
	int cnt=m;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j==t[i])continue;
			a[++cnt]=(edge){t[i],j,b[i][j]};
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	long long ans=0;
	for(int i=1;i<=cnt;i++)
	{
		int u=a[i].u,v=a[i].v,w=a[i].w;
		if(find(u)==find(v))continue;
		ans+=w;
		f[find(v)]=find(u);
	}
	cout<<ans;
}
long long res=1e18;
void solve2(string x)
{
	for(int i=1;i<=m;i++)
	{
		a[i]=e[i];
	}
	int cnt=m;
	long long ans=0;
	for(int i=1;i<=k;i++)
	{
		if(x[i]=='0')continue;
		ans+=c[i]+b[i][t[i]];
		for(int j=1;j<=n;j++)
		{
			if(j==t[i])continue;
			a[++cnt]=(edge){t[i],j,b[i][j]};
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=cnt;i++)
	{
		int u=a[i].u,v=a[i].v,w=a[i].w;
		if(find(u)==find(v))continue;
		ans+=w;
//		cout<<u<<' '<<v<<' '<<w<<endl;
		f[find(v)]=find(u);
	}
	res=min(ans,res);
//	cout<<x<<' '<<ans<<' '<<res<<endl;
}
void dfs(int d,string x)
{
	if(d>k)
	{
		solve2(x);
		return;
	}
	dfs(d+1,x+'0');
	dfs(d+1,x+'1');
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
		e[i]=a[i];
	}
	int flag=1;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)flag=0;
		b[i][0]=2e9;
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
			if(b[i][j]<=b[i][t[i]])t[i]=j;
		}
		flag&=(b[i][t[i]]==0);
	}
	if(flag)
	{
		solve();
		return 0;
	}
	dfs(1,"0");
	cout<<res;
	return 0;
}
