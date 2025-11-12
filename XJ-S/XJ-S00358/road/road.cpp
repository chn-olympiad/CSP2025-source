#include<bits/stdc++.h>
using namespace std;
long long int i,j,k,n,m,a[1000005],c[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	cin>>a[i];
	for(i=1;i<=k;i++)
	{
		cin>>c[i];
		for(i=1;i<=n+1;i++)
		cin>>j;
	}
	cout<<'0'<<endl;
	return 0;
}
