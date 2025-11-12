#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int u,v,w;
	int map[100005][100005];
	cin>>n>>m>>k;
	for(int i=1,i<=m;i++)
	{
		cin>>u>>v>>w;
		map[u][v]=w;
		map[v][u]=w;
	}
	return 0;
}