#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=10005;
struct edge
{
	int u,v,w;
};
vector<edge> g;
vector<edge> backup;
bool operator <(edge a,edge b)
{
	return a.w<b.w;
}

int n,m,k;
int c[N];
int fa[N];
int a[15][N];
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	else
	{
		return fa[x]=find(fa[x]);
	}
}
int kruskal()
{
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	sort(g.begin(),g.end());
	int ans=0;
	for(auto i:g)
	{
		if(find(i.u)!=find(i.v))
		{
			fa[find(i.u)]=find(i.v);
			ans+=i.w;

		}
	}
	return ans;
}
void solve_task_a()
{
	set<int> points;
	for(int i=1;i<=k;i++)
	{
		points.clear();
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==0)
			{
				points.insert(j);
			}
		}
		for(int j=1;j<=n;j++)
		{
			for(auto prev:points)
			{
				g.push_back({prev,j,a[i][j]});
			}
		}
	}
	cout<<kruskal()<<endl;
}

int bf(int mask)
{

	int add=0;
	for(int i=1;i<=k;i++)
	{
		if((mask>>(i-1))&1)
		{
			//use it
			add+=c[i];
			for(int u=1;u<=n;u++)
			{
				
				g.push_back({u,i+n,a[i][u]});
				
			}
		}
	}
	int ret=kruskal()+add;
	g=backup;
	return ret;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;

	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}
	backup=g;
	bool task_a=true;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]) task_a=false;
		bool flg=false;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==0)
			{
				flg=true;
			}
		}
		if(flg==false) task_a=false;
	}

	if(k==0)
	{
		cout<<kruskal()<<endl;
		return 0;
	}
	if(task_a)
	{
		solve_task_a();
		return 0;
	}
	int output=LLONG_MAX;
	for(int i=0;i<(1<<k);i++)
	{
		output=min(bf(i),output);
	}
	cout<<output<<endl;
}
