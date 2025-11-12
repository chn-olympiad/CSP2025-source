//崔雅欣  SN-S00182  西安铁一中滨河高级中学
#include<bits/stdc++.h>
using namespace std;
int n,m,k,mn,w[1000010][4],mu[1000010],xiang[11][1000010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i][1]>>w[i][2]>>w[i][3];
		mu[i]=w[i][3];
	}
	if(k=0)
	{
		for(int j=1;j<=n;j++)//最大 
		{
			for(int r=j;r<=m;r++)
			{
				if(mu[r]<mu[r-1]) 
				{
					swap(mu[r],mu[r-1]);
				}
			}
		}
		for(int c=1;c<=n-1;c++)
		{
			mn+=mu[c];
		}
	}
	else
	{
		for(int b=1;b<=k;b++)
		{
			for(int g=1;g<=n+1;g++)
			{
				cin>>xiang[b][g];
			}
		}
	}
	cout<<mn;
	return 0;
 } 
