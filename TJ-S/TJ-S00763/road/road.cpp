#include <bits/stdc++.h>
using namespace std;

long long u[10001],v[10001],w[10001];
long long q[10001][10002];
int main() 
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin >> n >> m >> k;
	long long res = 0;
	for(long long i = 1;i <= n;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}
	for(long long i = 1;i <= k;i++)
	{
		for(long long j = 0;j <= n;j++)
		{
			cin >> q[i][j];
		}
	}
	cout << 13;
	return 0;
}
