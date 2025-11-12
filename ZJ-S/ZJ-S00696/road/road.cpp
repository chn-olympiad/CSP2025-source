#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1e4 + 100;
const int M = 1e6 + 100;
const int K = 10 + 5;
struct Edge { int u, v, w; };
inline bool cmp(Edge x, Edge y) { return x.w < y.w; }
int n, m, k, ans = 1e18, c[K], fa[N + K];
vector<Edge> f; //new
vector<Edge> e, re;
int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
int res, cnt;
void findr() {
	sort(e.begin(), e.end(), cmp);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 0; i < e.size(); ++i) {
		int u = find(e[i].u), v = find(e[i].v);
		if(u != v) re.push_back(e[i]), fa[u] = v, ++cnt;
		if(cnt == n - 1) break;
	}
}
inline void merge(int u, int v, int w) {
	u = find(u), v = find(v);
	if(u != v) ++cnt, res += w, fa[u] = v;
}
inline void Mst(int s) {
	res = cnt = 0;
	for(int i = 1; i <= n + k; ++i) fa[i] = i;
	for(int i = 0; i < k; ++i)
		if(s >> i & 1) res += c[i + 1];
	int popc = __builtin_popcount(s);
	int cur = 0;
	for(int i = 0; i < re.size(); ++i) {
		while(cur < f.size()) {
			if(!(s >> (f[cur].u - 1) & 1)) { ++cur; continue; }
			if(f[cur].w <= re[i].w) merge(f[cur].u + n, f[cur].v, f[cur].w), ++cur;
			else break;
		}
		merge(re[i].u, re[i].v, re[i].w);
		if(cnt == n + popc - 1 || res >= ans) break;
	}
	if(res >= ans) return;
	while(cnt < n + popc - 1 && cur < f.size()) {
		if(!(s >> (f[cur].u - 1) & 1)) { ++cur; continue; }
		merge(f[cur].u + n, f[cur].v, f[cur].w), ++cur;
		if(res >= ans) break;
	}
	ans = res;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	for(int i = 1; i <= k; ++i) {
		cin >> c[i];
		for(int j = 1, x; j <= n; ++j) cin >> x, f.push_back({i, j, x});
	}
	findr();
	sort(f.begin(), f.end(), cmp);
	for(int s = 0; s < (1 << k); ++s) Mst(s);
	cout << ans << '\n';
	return 0;
}