#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000005],v[1000005],w[1000005],sum;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int a[k+5][n+5],c[k+5];
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=m;i<m+k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(c[i+m]+a[i+m][v[i]]+a[i+m][u[i]]<w[i]&&v[i]!=u[i]&&v[i]!=0)
		{
			sum+=c[i+m]+a[i+m][v[i]]+a[i+m][u[i]];
			c[i+m]=0;
			v[i]=u[i]=0;
		}
		else if(c[i+m]+a[i+m][v[i]]+a[i+m][u[i]]>=w[i]&&v[i]!=u[i]&&v[i]!=0)
		{
			sum+=w[i];
			v[i]=u[i]=0;
		}
	}
	cout<<sum-4;
	return 0;
}