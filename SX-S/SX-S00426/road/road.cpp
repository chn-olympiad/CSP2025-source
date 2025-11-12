#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int maxn = 1e4 + 1, maxm = 2e6 + 1, maxk = 11;
int n = 0, m = 0, k = 0, c[maxk], a[maxk][maxn];
bool used[maxk];

struct edge
{
	int from = 0, to = 0, len = 0, special = 0;
	edge() = default;
	edge(int f, int t, int l, int s): from(f), to(t), len(l), special(s) {}
	double value() {return len + 1.0 * c[special] / n / (n - 1);}
};
vector<edge> e;
inline bool comp(edge& a, edge& b)
{
	return (a.value() < b.value());
}
struct mfs
{
	int fa[maxm];
	inline int root(int x)
	{
		if(fa[x] == x) return x;
		return fa[x] = root(fa[x]);
	}
	inline bool merge(int x, int y)
	{
		int fx = root(x), fy = root(y);
		if(fx == fy) return false;
		fa[fy] = fx;
		return true;
	}
} s;
inline void fastread(int& x)
{
	x = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c))
	{
		x = (x << 1) + (x << 3) + (c - '0');
		c = getchar();
	}
}
inline void fastprint(int x)
{
	if(x > 9) fastprint(x / 10);
	putchar(x % 10 + '0');
}

inline lint kruskal()
{	
	int cnt = 0;
	lint ans = 0;
	iota(s.fa + 1, s.fa + n + 1, 1);
	sort(e.begin(), e.end(), comp);
	for(int i = 0; i < e.size() && cnt < n - 1; ++i)
		if(s.merge(e[i].from, e[i].to))
		{
			used[e[i].special] = true;
			++cnt;
			ans += e[i].len;
		}
	for(int i = 1; i <= k; ++i)
		if(used[i]) ans += c[i];
	return ans;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	fastread(n);
	fastread(m);
	fastread(k);
	for(int i = 1, u = 0, v = 0, w = 0; i <= m; ++i)
	{
		fastread(u);
		fastread(v);
		fastread(w);
		e.emplace_back(u, v, w, 0);
		e.emplace_back(v, u, w, 0);
	}
	for(int i = 1; i <= k; ++i)
	{
		fastread(c[i]);
		for(int j = 1; j <= n; ++j)
			fastread(a[i][j]);
		for(int p1 = 1; p1 <= n; ++p1)
			for(int p2 = p1 + 1; p2 <= n; ++p2)
			{
				e.emplace_back(p1, p2, a[i][p1] + a[i][p2], i);
				e.emplace_back(p2, p1, a[i][p1] + a[i][p2], i);
			}
	}
	fastprint(kruskal());
	fclose(stdin);
	fclose(stdout);
	return 0;
}
