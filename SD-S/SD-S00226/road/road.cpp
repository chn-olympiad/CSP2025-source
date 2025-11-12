
#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 1000010;
const int inf = 2e9;
const int mod = 998244353;

namespace Luminescent
{
	struct DSU
	{
		signed fa[11010], siz[11010];
		inline DSU()
		{
			iota(fa, fa + 11010, 0);
			fill(siz, siz + 11010, 1);
		}
		inline void init(signed maxn)
		{
			iota(fa, fa + maxn + 1, 0);
			fill(siz, siz + maxn + 1, 1);
		}
		inline signed find(signed x)
		{
			return x == fa[x] ? x : fa[x] = find(fa[x]);
		}
		inline signed merge(signed x, signed y)
		{
			x = find(x), y = find(y);
			if (x != y)
			{
				if (siz[x] > siz[y])
					x ^= y ^= x ^= y;
				siz[y] += siz[x];
				return fa[x] = y, 1;
			}
			return 0;
		}
	};
} using namespace Luminescent;

namespace Loyalty
{
	inline void test____01()
	{
		int C[20][20] = {0};
		for (int i = 0; i <= 19; ++i)
		{
			C[i][0] = 1;
			for (int j = 1; j <= i; ++j)
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
		int s = 0;
		for (int i = 0; i <= 10; ++i)
			s += (i + 1) * 10000 * C[10][i];
		cout << s << '\n';
	}
	struct Edge
	{
		int u, v, w;
		inline bool operator<(const Edge &r) const
		{
			return w < r.w;
		}
	} e[N], ex[12][10010];
	int cost[100], a[12][10010];
	inline void solve(int ca_, int atc_)
	{
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 1; i <= m; ++i)
			cin >> e[i].u >> e[i].v >> e[i].w;
		sort(e + 1, e + m + 1);
		DSU dsu;
		long long res = 0;
		int idx = 0;
		for (int i = 1; i <= m; ++i)
		{
			int u = e[i].u, v = e[i].v, w = e[i].w;
			if (dsu.merge(u, v))
				res += w, ex[0][++idx] = {u, v, w};
		}
		assert(idx == n - 1);
		for (int i = 1; i <= k; ++i)
		{
			cin >> cost[i];
			for (int j = 1; j <= n; ++j)
			{
				int x;
				cin >> x;
				ex[i][j] = {i + n, j, x};
			}
			sort(ex[i] + 1, ex[i] + n + 1);
		}
//		cerr << "!!!\n";
		for (int i = (1 << k) - 1; i; --i)
//		for (int i = 1; i < (1 << k); ++i)
		{
//			if (i % 20 == 0)
//				cerr << i << '\n';
			dsu.init(n + k);
			int cnt = 0, pos[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			long long fx = 0;
			for (int j = 1; j <= k; ++j)
				if (i >> (j - 1) & 1)
					fx += cost[j];
			if (fx >= res)
				continue;
			while (1)
			{
				int id = -1, mi = inf;
				for (int j = 0; j <= k; ++j)
					if (!j || (i >> (j - 1) & 1))
						if (j && pos[j] <= n || !j && pos[j] < n)
							if (ex[j][pos[j]].w < mi)
								mi = ex[j][pos[j]].w, id = j;
				// edge = ex[j][pos[j]]
//				assert(~id);
				int u = ex[id][pos[id]].u, v = ex[id][pos[id]].v, w = ex[id][pos[id]].w;
				if (dsu.merge(u, v))
				{
					++cnt, fx += w;
					if (fx >= res)
						break;
				}
				++pos[id];
				int ok = 1;
				for (int i = 2; i <= n; ++i)
					if (dsu.find(i) != dsu.find(1))
					{
						ok = 0;
						break;
					}
				if (ok)
					break;
			}
			res = min(res, fx);
		}
		cout << res << '\n';
	}
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout << fixed << setprecision(15);
	int T = 1;
//	cin >> T;
	for (int i = 1; i <= T; ++i)
		Loyalty::solve(i, T);
	return 0;
}

// rp++
// 12499 12499 12499
// please ac

