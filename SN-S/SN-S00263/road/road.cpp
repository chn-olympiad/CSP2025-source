#include<bits/stdc++.h>
#define int long long 
using namespace std;
struct edge
{
	int x,y,z;
};
int n,m,k,ans ;
vector<pair<int,int>> g[10100];
bool vis[10100];
vector<edge> e;
bool cmp(edge &a,edge &b)
{
	return a.z<b.z;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
		edge a;
		a.x=x;a.y=y;a.z=z;
		e.push_back(a);
	}
	if(k==0)
	{
		sort(e.begin(),e.end(),cmp);
		for(auto x:e)
		{
			if(vis[x.x]&&vis[x.y])
				continue;
			vis[x.x]=true;
			vis[x.y]=true;
			ans+=x.z;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
	
}
