#include<bits/stdc++.h>
using namespace std;
long long f[1009][1009],w[1009][1009];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		long long m1,m2,m3;
		scanf("%lldll%dll%d",m1,m2,m3);
		f[m1][m2]=f[m2][m1]=m3;
	}
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	f[i][j]=1000000000;
	long long maxx=-999;
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	for(int k=1;i<=n;i++)
	f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	maxx=max(maxx,f[i][j]);
	cout<<maxx;
	return 0;
}

