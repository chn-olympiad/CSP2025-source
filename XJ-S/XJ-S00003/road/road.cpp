#include<bits/stdc++.h>
using namespace std;
int u[1000005],v[1000005],w[1000005],a[1000005],p[1000005]={0};
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		p[u[i]]++;
		p[v[i]]++;
	}
	int d=0;
	for(int i=1;i<=m;i++)
	{
		if(p[i]==1)
		{
			d=i;
			break;
		}
	}
	
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
	} 
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			if(w[j]<w[i])
			{
				swap(w[j],w[i]);
				swap(u[j],u[i]);
				swap(v[j],v[i]);
				if(i==d)
				{
					d=j;
				}
				else if(j==d)
				{
					d=i;
				}
			}
		}
	}
	int sum=0;
	for(int i=1;i<=m-1;i++)
	{
		sum+=w[i];
	}
	if(d<=m-1)
	{
		cout<<sum;
		return 0;
	}
	else
	{
		cout<<sum-w[m-1]+w[m];
		return 0;
	}
}
