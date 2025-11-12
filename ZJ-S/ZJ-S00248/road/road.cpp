#include	<algorithm>
#include	<iostream>
#include	<vector>
#include	<tuple>
#define		int		long long
using namespace std;
using pii = pair<int,int>;
using t3i = tuple<int,int,int>;
constexpr int maxn = 1e4+13;
constexpr int maxm = 1e6+4;
constexpr int maxk = 13;
constexpr int inf = 0x3f3f3f3f3f3f3f3f;

int n, m, k;
int c[maxk];
vector<t3i> e;
int a[maxk][maxn];
namespace DSU
{
	int h[maxn];
	int rt[maxn];
	int find (int x)
	{
		if (rt[x] == x)
			return x;
		else
			return rt[x] = find (rt[x]);
	}
	void build (int n)
	{
		for (int i = 1; i <= n; i++)
		{
			h[i] = 1;
			rt[i] = i;
		}
	}
	void unite (int x, int y)
	{
		if ((x = find (x)) == find (y = find (y))) return ;
		if (h[x] < h[y])
			rt[x] = y;
		else
		{
			rt[y] = x;
			if (h[x] == h[y])
				h[x]++;
		}
	}
}
using namespace DSU;

int kruskal (void)
{
	build (n + k);
	int ans = 0;
	sort (e.begin(), e.end());
	for (auto [w, u, v] : e) if (find (u) != find (v))
	{
		ans += w;
		unite (u, v);
	}
	return ans;
}

signed main (void)
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int u, v, w, i = 1; i <= m; i++)
	{
		scanf ("%lld%lld%lld", &u, &v, &w);
		e.emplace_back(w, u, v);
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			scanf ("%lld", &a[i][j]);
	}
	if ([&] ()
	{
		for (int i = 1; i <= k; i++)
		{
			if (c[i])
				return 0;
			int flag = 0;
			for (int j = 1; j <= n; j++)
			{
				if (!a[i][j])
				{
					flag = 1;
					break;
				}
			}
			if (!flag)
				return 0;
		}
		return 1;
	}())				// Constraint A
	{
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++) if (!a[i][j])
			{
				for (int k = 1; k <= n; k++)
					e.emplace_back(a[i][k], j, k);
				break;
			}
		}
		cout << kruskal () << endl;
	}
	else
	{
		int ans = 0;
		build (n);
		sort (e.begin(), e.end());
		vector<t3i> tmp;
		for (auto [w, u, v] : e) if (find (u) != find (v))
		{
			ans += w;
			unite (u, v);
			tmp.emplace_back(w, u, v);
		}
		e = tmp;
		for (int st = 0; st < (1 << k); st++)
		{
			int sum = 0;
			e.resize(n - 1);
			for (int i = 1; i <= k; i++) if (st & (1 << (i - 1)))
			{
				sum += c[i];
				for (int j = 1; j <= n; j++)
				{
					for (int k = j + 1; k <= n; k++)
						e.emplace_back(a[i][j] + a[i][k], j, k);
				}
			}
			ans = min (ans, sum + kruskal ());
		}
		cout << ans << endl;
	}
	return 0;
}
