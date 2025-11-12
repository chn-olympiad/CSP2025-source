#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,u[1000005],v[1000005],w[1000005],c[15],a[15][10005],num[10005][10005],cnt,sum[100005],vis[15],ans,f[10020][10020],p;
int main()
{
	//freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i];
		num[u[i]][++cnt]=i;
		cin>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=2e9;
		for(int j=1;j<=m;j++)
			if((u[j]==i||v[j]==i)&&f[i][j]==0)
				if(sum[i]>w[j])
				{
					sum[i]=w[j];
					p=j;
				}
		for(int j=1;j<=k;j++)
		{
			if(vis[i]==0)
				if(sum[i]>c[j]+a[j][i])
				{
					sum[i]=c[j]+a[j][i];
					p=0;
					vis[i]=1;
				}
				
			else
				if(sum[i]>a[j][i])
				{
					sum[i]=a[j][i];
					p=0;
				}
		}
		f[p][i]=1;
	}
	for(int i=1;i<=n;i++)
		ans+=sum[i];

	cout<<ans;
	return 0;
}
