#include <bits/stdc++.h>

using namespace std;
long long sum,n,m,k,minn=96,sum_a;
long long u[1000005],v[1000005],w[1000005],c[1000005];
void dfs(int d,int f,int cnt)
{
	cnt=1;
	if(cnt==4)
	{
		minn=min(minn,sum_a);
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(v[i]==u[j]&&u[j]!=-100)
			{
				u[j]=-100;
				sum_a+=w[i];
				dfs(v[i],sum+w[i],cnt+1);
			}
		}
	}
	
	
	
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>c[j];
		}
	}
	dfs(u[1],v[1],0);
	cout<<minn; 
	return 0;
}
