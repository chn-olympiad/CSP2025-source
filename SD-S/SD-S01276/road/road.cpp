#include<bits/stdc++.h>
#define maxn 10010
using namespace std;
vector <int> edge[maxn];
vector <int> val[maxn];
int n,m,k;
int c[maxn];
int fa[maxn];
int main()
{
	freopen("road.in","r",stdin);	
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edge[u].push_back(v);
		edge[v].push_back(u);
		val[u].push_back(w);
		val[v].push_back(w);
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		int b[maxn],p=0;
		bool vis[maxn];
		for(int j=1;j<=n;j++)
		{
			cin>>b[j];
			if(b[j]==0)p=j;
		}
		//i==p
		vis[p]=1;
		for(int j=0;j<edge[p].size();j++)
		{
			int to=edge[p][j],w=val[p][j];
			if(w>b[to])
			{
				for(int k=0;k<edge[to].size();k++)
				{
					if(edge[to][k]==p)
						val[to][k]=b[to];
				}
				val[p][j]=b[to];
			}
			vis[to]=1;
		}
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==1)continue;
			edge[p].push_back(j);
			edge[j].push_back(p);
			val[p].push_back(b[j]);
			val[j].push_back(b[j]);
		}
	}
	int vis[maxn],low[maxn];
	memset(low,0x3f,sizeof(low));
	int p=1;
	low[p]=0;
	vis[p]=1;
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=edge[p].size();j++)
		{
			if(vis[j]==1)continue;
			int to=edge[p][j],w=val[p][j];
			if(low[to]>low[p]+w)low[to]=low[p]+w;
		}
		for(int j=1;j<=n;j++)
			if(low[j]<low[p]&&vis[j]==0)p=j;
		vis[p]=1;
		ans+=low[p];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
