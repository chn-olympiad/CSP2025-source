#include<bits/stdc++.h>
using namespace std;
const int inf=1e4+1;
long long n,m,k,u,v,w,money[inf];
bool conect[inf][inf],country[inf];
long long road[inf][inf];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(road,inf,sizeof(road));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		road[u][v]=road[v][u]=min(road[u][v],w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>money[i];
		for(int j=1;j<=n;j++)
		{
			cin>>w;
			road[j][n+i]=road[n+i][j]=min(road[j][n+i],w);
		}
	}
	//djsk();
	return 0;
}
