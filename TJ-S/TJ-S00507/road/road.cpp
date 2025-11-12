#include <bits/stdc++.h>
using namespace std;
int n,m,k,e[1015][1015],f[1015],ans;
bool c[1015];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(e,-1,sizeof(e));
	memset(f,0x3f,sizeof(f));
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[u][v]=w;
		e[v][u]=w;
	}
	for (int i=1;i<=k;i++)
	{
		int p;
		cin>>p;
		for (int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			e[j][i+n]=w;
			e[i+n][j]=w;
		}
	}
	queue<int>q;
	q.push(1);
	f[1]=0;
	c[1]=true;
	while (!q.empty())
	{
		int p=q.front();
		q.pop();
		for (int i=1;i<=n+k;i++)
		{
			if (e[i][p]>=0 && !c[i])
			{
				c[i]=true;
				q.push(i);
				f[i]=min(f[i],f[p]+e[i][p]);
			}
		}
	}
	for (int i=1;i<=n+k;i++)
	{
		if (f[i]==f[1014])
		{
			continue;
		}
		ans=max(ans,f[i]);
	}
	cout<<ans;
} 
