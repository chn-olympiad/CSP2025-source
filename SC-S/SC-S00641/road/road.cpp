#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000005],v[1000005],w[1000005],c[1000005],a[15][1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long ans1=0;
	for(long long i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		ans1+=w[i];
	}
	long long ans=1e18;
	for(long long i=1;i<=k;i++)
	{
		long long sum=0;
		cin>>c[i];
		sum+=c[i];
		for(long long j=1;j<=n;j++)
		{
			cin>>a[i][j];
			sum+=a[i][j];
		}
		ans=min(ans,sum);
	}
	cout<<min(ans,ans1);
	return 0;
}