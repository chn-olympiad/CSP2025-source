#include<iostream>
using namespace std;
int u[10005],v[10005],w[10005],a[10005],minn[1005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,i,j,sum=0;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>a[i];
		}	
	} 
	for(i=1;i<=1005;i++)
	{
		minn[i]=999;
	}
	for(i=1;i<=n;i++)
	{
		if(w[i]<minn[i])
		{
			minn[i]=w[i];
		}
	}
	for(i=1;i<=n/2;i++)
	{
		sum+=minn[i];
	}
	cout<<sum;
	return 0;
}
