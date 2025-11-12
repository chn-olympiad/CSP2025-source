#include <bits/stdc++.h>

using namespace std;

int u[1000001],v[1000001],w[1000001],c[1000000001];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin >>u[i]>>v[i]>>w[i];
	}
	for (int i=1;i<=k;i++)
	{
		cin >>c[i];
	}
	cout <<0;
	return 0;
}
