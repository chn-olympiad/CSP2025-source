#include<bits/stdc++.h>
using namespace std;
int u[1000010],v[1000010],w[1000010],c[20],a[20][10010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,s=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		s=s+w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<s;
	
	return 0;
}