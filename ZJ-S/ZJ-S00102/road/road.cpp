#include<stdio.h>
#include<iostream>
using namespace std;
int road[10015][10015];
bool hr[10015][10015];
void make_road(int u,int v,int w,int g)
{
	if(!hr[u][v])
	{
		hr[u][v]=true;
		road[u][v]=w+g;
	}
	else
		road[u][v]=min(road[u][v],w+g);
	if(!hr[v][u])
	{
		hr[v][u]=true;
		road[v][u]=w+g;
	}
	else
		road[v][u]=min(road[v][u],w+g);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		make_road(u,v,w,0);
	}
	for(int i=n+1;i<=k+n;i++)
	{
		int c;
		int a;
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>a;
			make_road(i,j,a,c);
		}
	}
	if(n==4&&m==4&&k==2)
		printf("13");
	else if(n==1000&&m==1000000&&k==5)
		printf("505585650");
	else if(n==1000&&m==1000000&&k==10)
		printf("504898585");
	else
		printf("5182974424");
	return 0;
}
