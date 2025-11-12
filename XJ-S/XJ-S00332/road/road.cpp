#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,k,ans,minn=INT_MAX;
long long c[N],a[20][N],fa[N];
map<long long,long long> connect;
struct node 
{
	long long v,w;
	bool ran;
};
vector<node> p[N];
long long find_val(long long a,long long b)
{
	for(auto &i:p[a])
	{
		if(i.v==b)
		return i.w;
	}
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(connect[i]==0)
		return false;
	}
	return true;
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
void dfs(long long now,long long ans)
{
	if(check())
	{
		minn=min(minn,ans);
		return ;
	}
	for(auto &i:p[now])
	{
		if(connect[i.v]==0)
		{
			connect[i.v]=1;
			dfs(i.v,ans+find_val(now,i.v));
			connect[i.v]=0;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		p[u].push_back({v,w});
		p[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			p[n+i].push_back({j,a[i][j]});
			p[j].push_back({n+i,a[i][j]});
		}
	}
	for(int i=1;i<=n;i++)
	{
		sort(p[i].begin(),p[i].end(),cmp);
	}
	connect[1]=1;
	dfs(1,0);
	cout<<minn<<endl;
	return 0;
}
