#include<iostream>
#include<cmath>
using namespace std;
int road[1010][1010],c[20],town[20][1010];
int dp[1010];
int n,m,k;
int mimimi;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int x1,x2,x3;
		cin>>x1>>x2>>x3;
		road[x1][x2]=x3;
	}
	for(int i=0;i<k;i++)
	{
		int x1;
		cin>>x1;
		c[i]=x1;
		for(int j=0;j<n;j++)
		{
			cin>>town[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		int minm=2147483647,minu=0;
		bool flag=0;
		for(int d=0;d<i;d++)
		{
			if(road[d][i]!=0)
			{
				if(road[d][i]+dp[d]<=minm)
				{
					minm=road[d][i]+dp[d],minu=d;
				}
			}
		}
		for(int d=0;d<20;d++)
		{
			if(town[d][i]!=0)
			{
				if(town[d][i]+c[d]<minm)
				{
					minm=town[d][i]+c[d],minu=d;
					flag=1;
				}
			}
		}
		dp[i]=minm;
	}
	cout<<dp[n-1];
}
