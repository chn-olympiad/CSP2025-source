//SN-S00294 把小煜 西安辅轮中学
#include<bits/stdc++.h>
#define int long long
#define ull unsinged long long
using namespace std;
int n,m,k;
struct node
{
	int u,v,w;
};
vector<node>G; 
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int t()
{
	sort(G.begin(),G.end(),cmp);
	int step=0,ret=0;
	bool vis[10010]={};
	while(1)
	{
		int u=G[step].u,v=G[step].v;
		if(vis[u] && vis[v]) continue;
		vis[u]=1; vis[v]=1;
		ret+=G[step].w; step++; 
		if(step==n-1) return ret;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//记得检查：
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--)
	{
		node x;cin>>x.u>>x.v>>x.w;
		G.push_back(x);
	}
	cout<<t();
	return 0;
}
