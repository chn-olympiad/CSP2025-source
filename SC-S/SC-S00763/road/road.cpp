#include<bits/stdc++.h>
using namespace std;
int n,m,k,y;
int u[100],v[100],w[100],c[100],a[100][100],b[100];
int main()
{
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];	
	}
	for(int j=1;j<=k;j++)
	{
		cin>>c[j];
		for(int i=1;i<=n;i++)
		{
			cin>>a[j][i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(w[i]>w[i+1])
		{
			int v;
			v=w[i+1];
			w[i+1]=w[i];
			w[i]=v;
		}
	}
	int u;
	for(int i=1;i<=m/2;i++)
	{
		u=w[i]+u;
	}
	cout<<u;
	return 0;
}