/*防伪标识：十年OI一场空，不开long long见祖宗*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct node{
	int v;
	long long w;
	friend bool operator >(node x,node y) {return x.w>y.w;}
	friend bool operator <(node x,node y) {return x.w<y.w;}
};
int n,m,k;
long long a[20][N],c[20];
vector<node> vc[N];
priority_queue<node,vector<node>,greater<node> > q;
bool vis[N];
long long bfs(int o)
{
	memset(vis,0,sizeof(vis));
	while(!q.empty()) q.pop();
	long long ans=0;
	q.push({1,0});
	while(!q.empty())
	{
		int u=q.top().v;
		long long nw=q.top().w;
		q.pop();
		if(vis[u]) continue;
		ans+=nw;
		vis[u]=1;
		for(node v:vc[u])
		{
			if(!vis[v.v])
			{
				q.push(v);
			}
		}
		if(u<=k&&(o&(1<<(u-1))))
		{
			for(int i=1;i<=n;i++)
			{
				if(!vis[i])
				{
					q.push({i,a[u][i]});
				}
			}
		}
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		long long w;
		scanf("%d%d%lld",&u,&v,&w);
		vc[u].push_back({v,w});
		vc[v].push_back({u,w});
	}
	
	for(int i=1;i<=k;i++)
	{
		bool flA=1;
		scanf("%lld",&c[i]);
		if(c[i]!=0) flA=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
			if(a[i][j]!=0) flA=0;
		}
		if(flA)
		{
			printf("0");
			return 0;
		}
	}
	//cout<<bfs(1);
	//return 0;
	long long ans=1e18;
	for(int i=0;i<(1<<k);i++)
	{
		long long he=0;
		for(int j=1;j<=k;j++)
		{
			if(i&(1<<(j-1))) he+=c[j]+a[j][j];
		}
		he+=bfs(i);
		ans=min(ans,he);
		//cout<<i<<" "<<he<<"\n";
	}
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 0 0 0
0 0 0 0 0

*/
