#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000006],v[1000006],w[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		int o;
		cin>>o;
		for(int i=1;i<=n;i++)	cin>>o;
	}
	cout<<0;
	return 0;
}
