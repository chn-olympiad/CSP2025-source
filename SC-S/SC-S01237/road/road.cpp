#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10005;
typedef pair<int, int> PII;
int n, m, k;
int c[N];
struct edge
{
	int u, v, w;
	bool operator < (edge x) { return w < x.w; }
} e[2000005];
int tot = 0;

int fa[N];
int ch = 0, S = 0;

inline int find(int k) { return fa[k] == k ? k : (fa[k] = find(fa[k])); }
inline void mrg(int a, int b) 
{ 
	a = find(a), b = find(b);
	if (a != b)
		fa[a] = b;
}
inline bool same(int a, int b) { return find(a) == find(b); }

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		e[++tot] = {u, v, w};
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++)
		{
			int x;
			scanf("%lld", &x);
			if (i == j)
				continue;
			e[++tot] = {i, j, x};
		}
	}
	sort(e + 1, e + tot + 1);
	for (int i = 1; i < n; i++)
	{
		edge x = e[i];
		int u = x.u, v = x.v, w = x.w;
		if (!same(u, v))
		{
			mrg(u, v);
			S += w;
		}
	}
	printf("%lld", S);
	return 0;
}