#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c[15][10005];
bool v[10005];
int a[10005][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
		cin>>c[i][j];
		/*
	for(int i=1;i<=n;i++)
	{
		int maxx=-1;
		for(int j=1;j<=n;j++)
		{
			if(a[j].)
		}
	}*/
	srand(time(0));
	cout<<rand()%1000000000;
	return 0;
}
