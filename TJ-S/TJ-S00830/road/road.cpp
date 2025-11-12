// stosto pingceji orzorz
// buyao WA TLE RE a
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),END##i=(b);i<=END##i;++i)
#define pre(i,a,b) for(int i=(a),END##i=(b);i>=END##i;--i)
using namespace std;
typedef long long ll;
// Problem: road
const int N = 1e4 + 15, M = 1.1e6 + 5;
struct edge
{
	int u, v, w;
	bool operator<(const edge o) const
	{
		return w < o.w;
	}
} e[M], e2[M], te[M];
int n, m, k, c[15], a[15][N], b[10005], q[10005]; ll tot, ans;
namespace dsu
{
	int f[N], sz[N];
	void init(const int n)
	{
		rep(i, 1, n) f[i] = i, sz[i] = 1; 
	}
	int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
	bool merge(int u, int v)
	{
		u = find(u); v = find(v);
		if (u == v) return 0;
		if (sz[u] > sz[v]) swap(u, v);
		f[u] = v; sz[v] += sz[u];
		return 1;
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, m) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	rep(i, 1, k)
	{
		scanf("%d", &c[i]);
		rep(j, 1, n) scanf("%d", &a[i][j]);
	}
//	sort(e + 1, e + m + 1);
	rep(i, 0, 2)
	{
		int t = 1;
		rep(j, 1, i) t *= 10000;
		rep(j, 1, m) ++ b[e[j].w / t % 10000];
		q[0] = b[0];
		rep(j, 1, 9999) q[j] = q[j - 1] + b[j];
		rep(j, 1, m) te[q[e[j].w / t % 10000] - (-- b[e[j].w / t % 10000])] = e[j];
		rep(j, 1, m) e[j] = te[j];
	}
	int cnt = 0;
	dsu::init(n);
	rep(i, 1, m)
	{
		if (dsu::merge(e[i].u, e[i].v))
		{
			tot += e[i].w;
			e2[++ cnt] = e[i];
		}
		if (cnt == n - 1) break;
	}
	ans = tot;
	rep(ti, 0, (1 << k) - 1)
	{
		int i = ti << 1, tc = cnt;
		ll t = 0; int nn = n;
		rep(j, 1, tc) e[j] = e2[j];
		rep(j, 1, k)
		{
			if (!(i >> j & 1)) continue;
			t += c[j]; ++ nn;
			rep(l, 1, n) e[++ tc] = {nn, l, a[j][l]};
		}
		if (t >= ans) continue;
//		sort(e + 1, e + tc + 1);
		rep(i, 0, 2)
		{
			int t = 1;
			rep(j, 1, i) t *= 10000;
			rep(j, 1, tc) ++ b[e[j].w / t % 10000];
			q[0] = b[0];
			rep(j, 1, 9999) q[j] = q[j - 1] + b[j];
			rep(j, 1, tc) te[q[e[j].w / t % 10000] - (-- b[e[j].w / t % 10000])] = e[j];
			rep(j, 1, tc) e[j] = te[j];
		}
		int qcnt = 0;
		dsu::init(nn);
		rep(j, 1, tc)
		{
			if (dsu::merge(e[j].u, e[j].v))
				t += e[j].w, ++ qcnt;
			if (qcnt == nn - 1 || t >= ans) break;
		}
		ans = min(ans, t);
	}
	printf("%lld", ans);
	return 0;
}

