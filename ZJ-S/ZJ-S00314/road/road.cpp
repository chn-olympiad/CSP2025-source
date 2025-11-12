//:56
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 100;
int n, m, k, fa[N];
pair <int, pair <int, int> > es[N];
int findroot(int x)
{
	if(fa[x] == x) return x;
	fa[x] = findroot(fa[x]);
	return fa[x];
}
int mst()
{
	sort(es + 1, es + 1 + m);
	int ans = 0, tot = 0;
	for(int i = 1; i <= m; i++)
	{
		int u = es[i].second.first, v = es[i].second.second, w = es[i].first;
		if(findroot(u) != findroot(v))
		{
			fa[fa[u]] = fa[v];
			tot++;
			ans += w;
			if(tot == n - 1)
			{
				break;
			}
		}
	}
	return ans;
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		es[i] = make_pair(w, make_pair(u, v));
	}
	int op = n;
	for(n = n + 1; n <= op + k; n++)
	{
		int iak;
		scanf("%lld", &iak);
		for(int i = 1; i <= op; i++)
		{
			int w;
			scanf("%lld", &w);
			es[++m] = make_pair(w, make_pair(n, i));
		}
	}
	for(int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	cout << mst();
}
