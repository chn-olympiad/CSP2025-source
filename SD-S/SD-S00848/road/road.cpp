#include<bits/stdc++.h>
using namespace std;
int m,n,k,u[1000005],v[1000005],w[1000005],a[15][1000005],s[15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{ 
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	return 0;
} 
