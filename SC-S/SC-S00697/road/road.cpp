#include <bits/stdc++.h>
using namespace std;

const int N=1e4+1,M=1e6+1,K=11,Max=0x7f;
int n,m,k,Map[N+K][N+K],Fix[N+K],ans;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
		for(int j=i;j<=n+k;j++)
			Map[i][j]=Map[j][i]=Max;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		Map[u][v]=Map[v][u]=min(Map[u][v],w);
	}
	for(int i=1;i<=k;i++)
	{
		int w;
		cin>>w;
		Fix[n+i]=w;
		for(int j=1;j<=n;j++)
		{
			int s;
			cin>>s;
			Map[n+i][j]=Map[j][n+i]=min(Map[n+i][j],s);
		}
	}
	for(int b=1;b<=n+k;b++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j==b)continue;
			for(int i=1;i<=n;i++)
			{
				int a=0;
				if(i==b||i==j)continue;
				if(b>n)a=Fix[b];
				Map[i][j]=Map[j][i]=min(Map[i][j],Map[i][b]+Map[b][j]+a);
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		ans+=Map[1][i];
	}
	cout<<ans;
	return 0;
}