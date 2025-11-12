#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e4 + 5;
const int M = 1e6 + 5;
struct edge {int u, v, w;};
edge e[M];
int n, m, k, fa[N], siz[N], c[N];
vector <edge> a[15];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
inline bool merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return 0;
	if (siz[x] > siz[y]) swap(x, y);
	fa[x] = y, siz[y] += siz[x];
	return 1;
}
inline bool cmp(edge x, edge y) {
	return x.w < y.w;
}
inline vector <edge> merge(vector <edge> &x, vector <edge> &y) {
	vector <edge> res(x.size() + y.size());
	vector <edge>::iterator p(x.begin()), q(y.begin()), i(res.begin());
	while (p != x.end() && q != y.end()) {
		if (p -> w < q -> w) *(i ++) = *(p ++);
		else *(i ++) = *(q ++);
	}
	while (p != x.end()) *(i ++) = *(p ++);
	while (q != y.end()) *(i ++) = *(q ++);
	return res;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i(1); i <= n; i = -~i) fa[i] = i, siz[i] = 1;
	for (int i(1); i <= m; i = -~i) cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i(1); i <= k; i = -~i) {
		cin >> c[i];
		for (int j(1); j <= n; j = -~j) {
			int w; cin >> w;
			a[i].emplace_back(edge{n + i, j, w});
		}
		sort(a[i].begin(), a[i].end(), cmp);
	}
	sort(e + 1, e + m + 1, cmp);
	vector <edge> E;
	for (int i(1); i <= m; i = -~i) 
		if (merge(e[i].u, e[i].v)) E.emplace_back(e[i]);
	ll ans = LLONG_MAX;
	for (int S(0); S < (1 << k); S = -~S) {
		ll now_ans = 0;
		for (int i(1); i <= n + k; i = -~i) fa[i] = i, siz[i] = 1;
		vector <edge> temp = E;
		for (int i(1); i <= k; i = -~i) 
			if (S >> (i - 1) & 1) temp = merge(temp, a[i]), now_ans += c[i];
		for (vector <edge>::iterator it(temp.begin()); it != temp.end(); ++ it) 
			if (merge(it -> u, it -> v)) now_ans += it -> w;
		ans = min(ans, now_ans);
	}
	cout << ans << '\n';
	return 0;
}