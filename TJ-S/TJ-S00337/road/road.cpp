#include <bits/stdc++.h>
using namespace std;

namespace p1
{
	const int MAXN = 1e3  + 10; // <test16
	const int MAXK = 15;
	int n, m, k;
	struct edge
	{
		int v, w;
	}
	vector<edge> e[MAXN];
	int a[MAXK][MAXN];
	int c[MAXK];
	void solve()
	{
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1; i <= m; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			e[u].push_back({v, w});
			e[v].push_back({u, w});
		}
		for(int i = 1; i <= k; i++)
		{
			scanf("%d", &c[i]);
			for(int j = 1; i <= n; j++) scanf("%d", &a[i][j]);
		}
	}
}

int main()
{
	
	return 0;
}
