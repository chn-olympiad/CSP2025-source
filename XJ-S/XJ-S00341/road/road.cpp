#include<bits/stdc++.h>
using namespace std;
long long int g[10005][10005],c[100],a[100][100005],s;
int main()
{
	long long int k,n,m,i,j,w,u,v,flag=0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
	}
	for(i=1;i<=k;i++)
	{
	cin>>c[i];
	if(c[i]!=0)
	flag=1;
	for(j=1;j<=n;j++)
	{
	cin>>a[i][j];
	if(a[i][j]!=0)
	flag=1;
	}
	}
	if(flag==0)
	cout<<0;
	return 0;
}
