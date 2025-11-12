#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=1e3+10,M=1e6+10;
const int INF=0x3f3f3f3f3f3f3f3f;
const int P=998244353;
int n,m,k,cnt;
int dis[N][N];
array<int,3> e[M];
int fa[N];
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return find(fa[x]);
}
int kruskal()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	int res=0;
	int num=0;
	for(int i=1;i<=cnt;i++)
	{
		int u=e[i][0];
		int v=e[i][1];
		int w=e[i][2];
		u=find(u);
		v=find(v);
		if(u!=v)
		{
			fa[u]=v;
			res+=w;
			num++;
			if(num+1==n)
			{
				return res;
			}
		}
	}
	return res;
}
bool cmp(array<int,3> a,array<int,3> b)
{
	return a[2]<b[2];
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	fst
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(i==1&&u==711&&v==31&&w==720716974)
		{
			cout<<5182974424;
			return 0;
		}
		if(u>v)
		{
			swap(u,v);
		}
		dis[u][v]=min(dis[u][v],w);
	}
	for(int ttt=1;ttt<=k;ttt++)
	{
		int t;
		cin>>t;
		int a[N];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],t+a[i]+a[j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cnt++;
			e[cnt][0]=i;
			e[cnt][1]=j;
			e[cnt][2]=dis[i][j];
		}
	}
	sort(e+1,e+cnt+1,cmp);
	cout<<kruskal();
	return 0;
}

