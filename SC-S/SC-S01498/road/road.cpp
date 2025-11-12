#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[100005][4];
int dp[100005];
int ans=0;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,c;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
		ans+=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>d[i][j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=n;l++)
			{
				a[j][l]=max(a[j][l],d[i][j]+d[i][l]);
			}
		}
	}
	cout<<ans;
	return 0;
}