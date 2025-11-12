// 许景焱 SN-S00654 西安铁一中滨河高级中学
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int maxn=10010;

struct Edge
{
	friend bool operator<(Edge a,Edge b);

	int u,v,w;
};

bool operator<(Edge a,Edge b)
{
	return a.w>b.w;
}

int n,m,k;
int fa[maxn+5],c[15];
vector<Edge>map,extra[15];
priority_queue<Edge>q;
long long ans=9223372036854775807;

int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}

void search(int status)
{
	long long val=0;
	for(int i=1; i<=n+k; i++)
		fa[i]=i;
	for(int i=1; i<=k; i++)
		if(status&(1<<(i-1)))
		{
			val+=c[i];
			if(val>=ans)
				return;
			for(Edge j:extra[i])
				q.push(j);
		}
	for(Edge i:map)
		q.push(i);
	for(Edge e; !q.empty();)
	{
		e=q.top();
		q.pop();
		if(find(e.u)!=find(e.v))
		{
			val+=e.w;
			if(val>=ans)
				return;
			fa[find(e.u)]=find(e.v);
		}
	}
	ans=min(val,ans);
}

signed main()
{
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w; i<=m; i++)
	{
		cin>>u>>v>>w;
		map.push_back(Edge {u,v,w});
	}
	for(int i=1; i<=k; i++)
	{
		cin>>c[i];
		for(int j=1,w; j<=n; j++)
		{
			cin>>w;
			extra[i].push_back(Edge {n+i,j,w});
		}
	}
	for(int i=0; i<(1<<k); i++)
		search(i);
	cout<<ans<<endl;
	return 0;
}
