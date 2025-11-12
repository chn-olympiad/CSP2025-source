#include<bits/stdc++.h>
using namespace std;
const long long int N=1e4+10,inf=1e8;
long long int n,m,k,dis[N],t[N],cnt[N],tot=0,ans=0;
struct edge{
	int v,w;
};
vector <edge> a[N];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q; 
void prim()
{
	while(!q.empty())
	{
		int u=q.top().second,w1=q.top().first;
		q.pop();
		if(t[u]) continue;
		t[u]=1;
		ans+=w1;
		for(int i=0;i<a[u].size();++i)
		{
			int v=a[u][i].v,w=a[u][i].w;
			if(dis[u]<dis[v]-w&&!t[v]) 
			{
			dis[v]=dis[u]+w;
			q.push({dis[v],v});
		    }
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back((edge) {y,z});
		a[y].push_back((edge) {x,z});
	}
	for(int i=2;i>=i;++i) dis[i]=inf;
	q.push({0,1});
	prim();
	cout<<ans;
	return 0;
}