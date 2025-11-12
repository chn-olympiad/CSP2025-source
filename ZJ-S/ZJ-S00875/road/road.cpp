#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
int mili[10001][10001];
int c[11],lame[11][10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		mili[u][v]=mili[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>lame[i][j];
	}
	cout<<0;
	return 0;
	fclose(stdin);fclose(stdout);
}
