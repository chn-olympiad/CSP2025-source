#include<bits/stdc++.h>
using namespace std;
int f[1000005],c[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0,a,b,c,s,i,j;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		sum=c;
	}
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=n+1;j++)
		{
			cin>>s;
		}
	}
	cout<<sum;
	return 0;
 } 
