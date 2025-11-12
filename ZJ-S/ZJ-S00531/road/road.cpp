#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10000 + 10 + 5;
int n, m, k, tot, c[N], fa[N], siz[N];
ll ans = LLONG_MAX, val;
struct edge {
	int u, v, w;
	edge() {}
	edge(int x, int y, int z) {
		u = x, v = y, w = z;
	}
	bool operator < (const edge &o) const {
		return w < o.w;
	}	
};
vector<edge> E, C[15], tmp;
inline int getfa(int x) {
	return fa[x] == x ? x : (fa[x] = getfa(fa[x]));
}
inline vector<edge> kruskal(const vector<edge> &e, int tar) {
	for (int i = 1; i <= n + k + 1; i++)
		fa[i] = i, siz[i] = 1;
	ll res = 0;
	vector<edge> out(tar - 1);
	int cnt = 0;
	for (auto [u, v, w] : e) {
		int fu = getfa(u), fv = getfa(v);
		if (fu != fv) {
			cnt++, res += w;
			if (siz[fu] > siz[fv])
				swap(fu, fv);
			fa[fu] = fv, siz[fv] += siz[fu];
			out[cnt - 1] = edge(u, v, w);
			if (cnt == tar - 1)
				break;
		}
	}
	ans = min(ans, res + val);
	return out;
}
inline void Merge(const vector<edge> &l, const vector<edge> &r, vector<edge> &res) {
	int i = 0, j = 0, k = 0;
//	for (auto [u, v, w] : l)
//		res.emplace_back(u, v, w);
//	for (auto [u, v, w] : r)
//		res.emplace_back(u, v, w);
//	sort(res.begin(), res.end());
	res.resize(l.size() + r.size());
	while (i < l.size() && j < r.size())
		if (l[i].w < r[j].w)
			res[k++] = l[i], i++;
		else
			res[k++] = r[j], j++;
	while (i < l.size())
		res[k++] = l[i], i++;
	while (j < r.size())
		res[k++] = r[j], j++;
}
inline void dfs(int d, vector<edge> &e) {
	if (d == k + 1) 
		return;
	dfs(d + 1, e);
	val += c[d], tot++;
	vector<edge> tmp = e;
	e.clear();
	Merge(tmp, C[d], e);
	e = kruskal(e, n + tot);
	dfs(d + 1, e);
	e = tmp;
	val -= c[d], tot--;
}
inline char gc() {
	return cin.get();
}
inline int read() {
	char ch = gc();
	int x = 0;
	while (!isdigit(ch))
		ch = gc();
	while (isdigit(ch))
		x = x * 10 + ch - 48, ch = gc();
	return x;
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	int e = 0;
	E.resize(m);
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read(), w = read();
		E[i - 1] = edge(u, v, w);
	}
//	return 0;
	for (int i = 1; i <= k; i++) {
		c[i] = read(), C[i].resize(n);
		for (int j = 1, w; j <= n; j++) 
			w = read(), C[i][j - 1] = edge(i + n, j, w);
		sort(C[i].begin(), C[i].end());
	}
//	return 0;
//	clock_t st = clock();
	sort(E.begin(), E.end());
	E = kruskal(E, n);
	dfs(1, E);
	cout << ans << '\n';
//	cerr << (1.0 * (clock() - st) / CLOCKS_PER_SEC) << '\n';
//	while (true);
	return 0;
}