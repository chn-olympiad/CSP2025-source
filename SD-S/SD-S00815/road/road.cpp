#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 3;
int u[maxn],v[maxn],w[maxn];
int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}
	return 0;
}
