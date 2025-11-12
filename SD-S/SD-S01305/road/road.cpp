#include<bits/stdc++.h>
using namespace std;
long long c[11],cn[10010];
long long f[1000010];
long long u[1000010],v[1000010],w[1000010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	  cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		  cin>>cn[j];
	}
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			if(u[i]!=u[i+1]&&v[i]!=v[i+1]) ans+=w[i];
		}
	}
	cout<<ans<<endl;
	return 0;
} 
