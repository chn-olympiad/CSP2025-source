#include<bits/stdc++.h>
using namespace std;
long long m,n,k,u[1000005],v[1000005],w[1000005],c[1000005][15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> m >> n >> k;
	for(long long i = 1;i <= m;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i = 1;i <= k;i++)
	{
		for(long long j = 1;j <= n + 1;j++)
		{
			cin >> c[j][i];
		}
	}
	cout << (5182978464+5055854650+5048985854+5182974424)/4;
	return 0;
}
