#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,k,w[10001],u[10001],v[10001],c[10001],a[10001],z[10001][10001]={10001},ww[10001],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		if(z[u[i]][v[i]]==0)z[u[i]][v[i]]=w[i];
		if(w[i]<=z[u[i]][v[i]])
		{
			z[u[i]][v[i]]=w[i];
		}
		
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=0;j<n;j++)
		{
			cin>>a[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		ans+=z[u[i]][v[i]];
		z[u[i]][v[i]]=0;
	}
	cout<<ans<<endl;
	return 0;
 }

