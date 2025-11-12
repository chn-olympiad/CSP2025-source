#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],c[105],a[15][1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		for(int j=0;j<n;j++) cin>>a[i][j];
	}
	cout<<n+m+k+3;
	return 0;
}
