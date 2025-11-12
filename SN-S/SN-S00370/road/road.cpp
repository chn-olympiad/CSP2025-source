#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=10000;
const int MAXK=10;
int n,m,k;
int c[MAXK+5];
int a[MAXK+5][MAXN+5];
struct node
{
	int u,v,w;
};
bool cmp(node x,node y)
{
	return x.w<y.w;
}
vector<node> e;
/*
1~n 城市 
n+1~n+k 农村 
0 超级原点
*/
//并查集
int fa[MAXN+MAXK+5];
int cnt[MAXN+MAXK+5];
int ans=1e18;
int findfa(int x)
{
	if(x==fa[x])
	{
		return x;
	}
	return fa[x]=findfa(fa[x]);
}
void init()
{
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
		cnt[i]=1;
	}
}
//--------
vector<int> v;//shengji
void dfs(int t)
{
	if(t==n+1)
	{
		int sum=0;
		for(int i:v)
		{
			sum+=c[i];
			for(int j=1;j<=n;j++)
			{
				e.push_back({n+i,j,a[i][j]});
			}
		}
		sort(e.begin(),e.end(),cmp);
		init();
		for(auto i:e)
		{
			int u=i.u;
			int v=i.v;
			int w=i.w;
			int fau=findfa(u);
			int fav=findfa(v);
			if(fau!=fav)
			{
				sum+=w;
				if(cnt[fau]>=cnt[fav])
				{
					cnt[fau]+=cnt[fav];
					fa[fav]=fau;
				}
				else
				{
					cnt[fav]+=cnt[fau];
					fa[fau]=fav;
				}
			}
		}
		cout<<sum<<'\n';
		ans=min(ans,sum);
		return;
	}
	v.push_back(t);
	dfs(t+1);
	v.pop_back();
	dfs(t+1);
}
signed main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
