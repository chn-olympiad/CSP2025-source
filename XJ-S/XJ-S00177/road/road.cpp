#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int u[M],v[M],w[M],n,m,k,c[15],a[N][15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,l,sum=0;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(i=1;i<=k;i++)
	{
		cin>>c[i];
		for(j=1;j<=n;j++)
		{
			cin>>a[j][i];
		}
	}
	for(i=1;i<=m;i++)
	{
		for(j=i;j<=m;j++)
		{
			if(w[i]>w[j])
			{
				swap(w[i],w[j]);
			}
		}
	}
	for(i=1;i<=m/2;i++)
	{
		sum+=w[i];
	}
	int minx=1e9;
	for(i=1;i<=k;i++)
	{
		minx=min(minx,c[i]);
	}
	sum+=minx;
	for(i=1;i<=k;i++)
	{
		if(c[i]==minx)
		{
			for(j=1;j<=n;j++)
			{
				for(l=j;l<=n;l++)
				{
					if(a[j][i]>a[l][i])
					{
						swap(a[j][i],a[l][i]);
					}
				}
			}
			for(j=1;j<=n/2;j++)
			{
				sum+=a[j][i];
			}
		}
	}
	cout<<sum;
	return 0;
}
