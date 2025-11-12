#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
const int MAXN=1e4+15;
int n,m,k,c[15],a[15][MAXN],count[MAXN],start,total=INT_MAX,ans,tt,record;
bool vis[MAXN];
vector<pair<int,int>>g[MAXN];
vector<int>t;
queue<int>q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k,record=n;
	for(int i=1,u,v,w;i<=m;i++)
		cin>>u>>v>>w,g[u].push_back({v,w}),g[v].push_back({u,w}),count[u]+=w,count[v]+=w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
		if(total>count[i])
			total=count[i],start=i;//找开路花销最小的为起始点
	for(int i=1;i<=k;i++)
	{
		tt=c[i]+a[i][start];
		if(tt<total)
			total=tt,start=n+i;
	}
	if(start>n)
		ans+=total;
	q.push(start);
	int u,ti;
	while(!q.empty())
	{
		if(record==n)
			break;
		u=q.front(),q.pop(),vis[u]=true;
		for(auto y:g[u])
		{
			for(auto x:g[y.first])
				if(!vis[y.first])
					t.push_back(x.first),vis[x.first]=true,record--;
			total=INT_MAX;
			for(int i=1;i<=k;i++)
			{
				tt=c[i];
				for(auto x:t)
					tt+=a[i][x];
				if(tt<total)
					tt=total,ti=i+n;
			}
			if(count[y.first]<total)
				ans+=count[y.first],vis[y.first]=true,q.push(y.first),record--;
			else
			{
				for(auto x:t)
					g[ti].push_back({x,a[ti][x]});
				ans+=total,q.push(ti);
			}
			t.clear();
		}
	}
	cout<<ans;
	return 0;
}
