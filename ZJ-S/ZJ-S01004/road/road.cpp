#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int inf=0x3f3f3f;
vector<int> a[N];
queue<int> q;
map<int,int> b[N];
int n,m,k,ans,maxn;
int x[20],vis[N],dis[N],dis1[N];
int main()
{
	freopne("road","r",stdin);
	freopne("road","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back(v);
		a[v].push_back(u);
		b[u][v]=w;
		b[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		int y;
		cin>>x[i];
		for(int j=1;j<=n;j++)
		{
			cin>>y;
			a[n+i].push_back(j);
			a[j].push_back(n+i);
			b[n+i][j]=x[i]+y;
			b[j][n+i]=x[i]+y;
		}
	}
		q.push(1);
		memset(dis,inf,sizeof(dis));
		dis[1]=0;
		while(!q.empty())
		{
			int t=q.front();
			q.pop();
			for(int i=0;i<a[t].size();i++)
			{
				int to=a[t][i];
				if(dis[to]>dis[t]+b[t][to])
				{
					dis[to]=dis[t]+b[t][to];
					dis1[to]=b[t][to];
					if(t>n) dis[to]-=x[t-n];
					q.push(to);
				}
				else if(dis[to]>dis[t]+b[t][to]-x[t-n]&&t>n)
				{
					dis[to]=dis[t]+b[t][to]-x[t-n];
					dis1[to]=b[t][to];
					q.push(to);
				}
				else if(b[t][to]<dis1[to]||b[t][to]-x[t-n]<dis1[to]&&t>n)
				{
					dis[to]=dis[t]+b[t][to];
					dis1[to]=b[t][to];
					if(t>n) dis[to]-=x[t-n];
					q.push(to);
				}
			}
		}
	for(int i=1;i<=n;i++)
		maxn=max(maxn,dis[i]);
	return 0;
}
