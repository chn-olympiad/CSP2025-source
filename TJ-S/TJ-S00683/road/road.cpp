#include<iostream>
using namespace std;
int n,m,k,u,v,w,g[10005][10005],c[11],a[11][10005];
int num=0;
long long s;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=w;
		num+=w;
	}
	for(int j=1;j<=k;j++)
	{
		cin>>c[j];
		for(int i=1;i<=n;i++)
		{
			cin>>a[j][i];
		}
	}
	cout<<num<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
