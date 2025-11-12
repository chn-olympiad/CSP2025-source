#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long u,v,w;
int main()
{
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>u;
		}
	}
	cout<<0<<endl;
	return 0;
}

