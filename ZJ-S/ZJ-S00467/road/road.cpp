#include<bits/stdc++.h>
using namespace std;
long long ans;
long long u[1005];
long long v[1006];
long long w[1005];
long long a[1005][1005];
long long c[1005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}

	for (int i=1;i<=k;i++)
	{
		cin>>c[i];
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}


	if(k==0)
	{
		for (int i=1;i<=m;i++)
		{
			ans+=w[i];
		}
	}
	else
	{
		for (int i=1;i<=m;i++)
		{
			ans+=w[i];
		}
		for (int i=1;i<=k;i++)
		{
			ans+=c[i];
			for (int j=1;j<=n;j++)
			{
				ans+=a[i][j];
			}
		}
	}

	cout<<ans;

	fclose(stdin);
	fclose(stdout);

	return 0;
}
