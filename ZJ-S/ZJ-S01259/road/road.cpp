#include<bits/stdc++.h>
using namespace std;
const int L=INT_MAX;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	long long v[n+5][n+5]={L},x[k+5][n+5],cx[k+5];
	long long dp[n+5][n+5]={L};
	for(int i=1;i<=m;i++)
	{
		int u,v1,w;
		cin>>u>>v1>>w;
		v[u][v1]=w;
		v[v1][u]=w;
	}
	long long ans=L;
	for(int i=1;i<=k;i++)
	{
		cin>>cx[i];
		for(int j=1;j<=n;j++)cin>>x[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(v[i][j]==L)continue;
			dp[i][j]=min(dp[i][j]+v[i][j],v[i][j]);
			ans=min(ans,dp[i][j]);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}