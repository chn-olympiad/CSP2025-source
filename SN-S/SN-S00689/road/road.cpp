#include <bits/stdc++.h>

using namespace std;

template <int SIZE>
class UQSet
{
	private:
	vector<int> p;
	
	public:
	void clear()
	{
		for (int i = 0; i <= SIZE; ++ i)
		{
			p[i] = i;
		}
	}
	
	UQSet()
	: p(SIZE + 1)
	{
		clear();
	}
	
	int find(int u)
	{
		return u == p[u] ? u : p[u] = find(p[u]);
	}
	
	void merge(int u, int v)
	{
		p[find(u)] = find(v);
	}
};

constexpr int N = 1e4 + 15, M = 2e6 + 5;
int n, kn, m, m0, m1;
long long c[N];
UQSet<N> uqs;

namespace Graph
{
	pair<pair<int, int>, long long> ed[M], ed0[M], ed1[M];
	long long ew[15][N];
	
	long long kruscal(int nn, int mm, pair<pair<int, int>, long long> *ed)
	{
		uqs.clear();
		sort(ed + 1, ed + mm + 1, [](const pair<pair<int, int>, long long> &ed1, const pair<pair<int, int>, long long> &ed2) -> bool
		{
			return ed1.second < ed2.second;
		});
		
		long long res = 0;
		for (int i = 1, cnt = nn; i <= mm; ++ i)
		{
			if (cnt == 1)
			{
				break;
			}
			
			int u = ed[i].first.first, v = ed[i].first.second;
			long long w = ed[i].second;
			
			if (uqs.find(u) == uqs.find(v))
			{
				continue;
			}
			-- cnt, res += w;
			uqs.merge(u, v);
		}
		
		return res;
	}
}

using namespace Graph;

int main()
{
	freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m >> kn;
	
	for (int i = 1; i <= m; ++ i)
	{
		cin >> ed[i].first.first >> ed[i].first.second >> ed[i].second;
	}
	
	uqs.clear();
	sort(ed + 1, ed + m + 1, [](const pair<pair<int, int>, long long> &ed1, const pair<pair<int, int>, long long> &ed2) -> bool
	{
		return ed1.second < ed2.second;
	});
	
	long long ans = 0;
	for (int i = 1, cnt = n; i <= m; ++ i)
	{
		if (cnt == 1)
		{
			break;
		}
		
		int u = ed[i].first.first, v = ed[i].first.second;
		long long w = ed[i].second;
		
		if (uqs.find(u) == uqs.find(v))
		{
			continue;
		}
		-- cnt, ans += w;
		uqs.merge(u, v), ed0[++ m0] = ed[i];
	}
	
	for (int i = 1; i <= kn; ++ i)
	{
		cin >> c[i];
		for (int j = 1; j <= n; ++ j)
		{
			cin >> ew[i][j];
		}
	}
	
	for (int st = 1; st < (1 << kn); ++ st)
	{
		m1 = m0;
		for (int i = 1; i <= m0; ++ i)
		{
			ed1[i] = ed0[i];
		}
		
		int kcnt = 0;
		long long csum = 0;
		for (int i = 1; i <= kn; ++ i)
		{
			if (((st >> (i - 1)) & 1) == 0)
			{
				continue;
			}
			
			++ kcnt, csum += c[i];
			for (int j = 1; j <= n; ++ j)
			{
				ed1[++ m1] = pair<pair<int, int>, long long>(pair<int, int>(n + kcnt, j), ew[i][j]);
			}
		}
		
		ans = min(ans, kruscal(n + kcnt, m1, ed1) + csum);
	}
	
	cout << ans << endl;
	return 0;
}
