#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e4 + 5;

int n, m, k, c[N], cnt;
std::vector<std::pair<int, int> > e[N];
std::vector<std::tuple<int, int, int> > point;

class dsu
{
private:
	std::vector<int> fa;
	
public:
	dsu(int n) : fa(n) { std::iota(fa.begin(), fa.end(), 0); }
	
	inline int find(const int &x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
	inline void merge(const int &x, const int &y) { fa[find(y)] = find(x); }
	inline bool is_merge(const int &x, const int &y) { return find(x) == find(y); }
};

inline int kurskal()
{
	dsu T(cnt + 5); int res = 0, cnt = 0;
	std::sort(point.begin(), point.end(), [](const std::tuple<int, int, int> &_, const std::tuple<int, int, int> &__){
		return std::get<2>(_) < std::get<2>(__);
	});
	for (auto i : point)
	{
		int u = std::get<0>(i), v = std::get<1>(i), w = std::get<2>(i);
		if (!T.is_merge(u, v))
		{
			T.merge(u, v);
			res += w, ++cnt;
			if (cnt == n - 1) return res;
		}
	}
	return -1;
}

signed main()
{
	std::freopen("road.in", "r", stdin);
	std::freopen("road.out", "w", stdout);
	
	std::cin >> n >> m >> k; cnt = n;
	for (int i = 1; i <= m; ++i)
	{
		int u, v, w; std::cin >> u >> v >> w;
		e[u].push_back(std::make_pair(v, w));
		e[v].push_back(std::make_pair(u, w));
		point.push_back(std::make_tuple(u, v, w));
	}
	
	if (k == 0)
	{
		std::cout << kurskal() << '\n';
		return 0;
	}
	
	bool flag = 0;
	
	for (int i = 1; i <= k; ++i)
	{
		std::cin >> c[i];
		if (c[i] != 0) flag = 1;
		++cnt;
		for (int j = 1; j <= n; ++j)
		{
			int t; std::cin >> t;
			point.push_back(std::make_tuple(cnt, j, t));
		}
	}
	
	if (!flag)
	{
		std::cout << kurskal() << '\n';
		return 0;
	}
	return 0;
}