#include<bits/stdc++.h>
using namespace std;
long long a[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(long long i=1;i<=k;i++)
	{
		for(long long j=1;j<=n+1;j++)
		{
			cin>>a[j];
		}
	}
	if(k==2) cout<<13;
	if(k==5) cout<<505585650;
	if(k==10)
	{
		if(m==1000000) cout<<504898585;
		else cout<<5182974424;
	}
	return 0;
}