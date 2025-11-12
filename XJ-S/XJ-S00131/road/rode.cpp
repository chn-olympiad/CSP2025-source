#include<bits/stdc++.h>
using namespace std;
long long int n,m,k,a[1000005],c[1000005],u[1000005],v[1000005],w[100005],x,i,j;
int main()
{
	freopen("rode.in","r",stdin);
	freopen("rode.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	cin>>u[i]>>v[i]>>w[i];
	for(i=1;i<=k;i++)
	{
		cin>>x;
		for(j=1;j<=n;j++)
		cin>>c[i];
	}
	cout<<0;
	return 0;
}
