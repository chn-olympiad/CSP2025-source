#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[10000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,k,n,m,sum=0,x;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{ 
		cin>>x>>m;
		cin>>b[i];
	}
	sort(b+1,b+n+2);
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=n+1;j++)
		{
			cin>>a[j];
		}
	}
	for(i=1;i<=n-1;i++)
	{
		sum+=b[i];
	}
	for(j=2;j<=n+1;j++)
	{
		cout<<b[j]<<" ";
	}
	cout<<sum;
	return 0;
}
