#include <bits/stdc++.h>
using namespace std;
struct Edge {
	int u, v, w;
	inline bool operator<(Edge f) const { return w < f.w; }
};
using ll = long long;
bool o1;
const int N = 1.1e6 + 10;
int n, m, k, fa[N];
Edge cur[12][N], vill[12][N];
int lencur[12];
inline void mergex(int u) // move u - 1 -> u
{
	for (int i = 1; i <= lencur[u - 1]; i++) cur[u][i] = cur[u - 1][i];
	for (int i = 1; i <= n; i++)
			cur[u][i + lencur[u - 1]] = vill[u][i];
	inplace_merge(cur[u] + 1, cur[u] + lencur[u - 1] + 1, cur[u] + lencur[u - 1] + n + 1);
	lencur[u] = lencur[u - 1] + n;
}
inline int find(int u) { return fa[u] == u ? u : (fa[u] = find(fa[u])); }
inline int solve(Edge *c, int len) {
	int cnt = 0;
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	for (int i = 1; i <= len; i++)
		if (find(c[i].u) != find(c[i].v)) {
			fa[find(c[i].u)] = find(c[i].v);
			++cnt;
			c[cnt] = c[i];
		}
	return cnt;
}
ll ans = 0x3f3f3f3f3f3f3f3f, cst[N];
void dfs(int u, ll extr) {
	if (u == k + 1) {
		--u;
		ll res = extr;
		for (int i = 1; i <= lencur[u]; i++) res += cur[u][i].w;
		ans = min(ans, res);
		return;
	}
	lencur[u] = lencur[u - 1];
	for (int i = 1; i <= lencur[u]; i++) cur[u][i] = cur[u - 1][i];
	dfs(u + 1, extr);
	mergex(u), lencur[u] = solve(cur[u], lencur[u]);
	dfs(u + 1, extr + cst[u]);
}
bool o2;

int main() {
	// cerr << (&o2 - &o1) / 1048576. << endl;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> cur[0][i].u >> cur[0][i].v >> cur[0][i].w;
	sort(cur[0] + 1, cur[0] + m + 1);
	for (int i = 1; i <= k; i++) {
		cin >> cst[i];
		for (int j = 1; j <= n; j++) vill[i][j].u = i + n, vill[i][j].v = j, cin >> vill[i][j].w;
		sort(vill[i] + 1, vill[i] + n + 1);
	}
	lencur[0] = solve(cur[0], m);
	// cerr << "find lencur:" << lencur[0] << endl;
	// for (int i = 1; i <= n; i++) assert(find(i) == find(1));
	dfs(1, 0);
	cout << ans << endl;
	// cerr << double(clock()) / CLOCKS_PER_SEC << endl;
	return 0;
}