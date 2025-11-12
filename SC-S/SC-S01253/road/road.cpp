#include <algorithm>
#include <cstdint>
#include <iostream>
#define int int64_t

using namespace std;

struct edge {
	int u, v, w;
	bool operator<(const edge& other) const {
		return w < other.w;
	}
};

constexpr int N = 1e4 + 10, M = 1e6 + 10, K = 10;
edge ed[M], ued[M], ted[N * K];
int n, m, k, cnt, ans, cw[K][N], ca[K], fa[N];

int findBoss(int u) {
	return fa[u] == u ? u : fa[u] = findBoss(fa[u]);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> ed[i].u >> ed[i].v >> ed[i].w;
	for (int i = 0; i < k; i++) {
		cin >> ca[i];
		for (int j = 1; j <= n; j++)
			cin >> cw[i][j];
	}
	sort(ed + 1, ed + m + 1);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++)
		if (findBoss(ed[i].u) != findBoss(ed[i].v))
			ans += ed[i].w, fa[findBoss(ed[i].u)] = findBoss(ed[i].v), ued[++cnt] = ed[i];
	for (int state = 1; state < (1 << k); state++) {
		int res = 0, ttop = 0;
		for (int i = 0; i < k; i++) {
			if (state >> i & 1) {
				res += ca[i];
				for (int j = 1; j <= n; j++)
					ted[++ttop] = {i + n + 1, j, cw[i][j]};
			}
		}
		sort(ted + 1, ted + ttop + 1);
		for (int i = 1; i <= n + k; i++) fa[i] = i;
		for (int i = 1, j = 1; i < n || j <= ttop;) {
			if (!(i < n) || ted[j].w < ued[i].w) {
				if (findBoss(ted[j].u) != findBoss(ted[j].v))
					res += ted[j].w, fa[findBoss(ted[j].u)] = findBoss(ted[j].v);
				j++;
			} else {
				if (findBoss(ued[i].u) != findBoss(ued[i].v))
					res += ued[i].w, fa[findBoss(ued[i].u)] = findBoss(ued[i].v);
				i++;
			}
		}
		ans = min(ans, res);
	}
	cout << ans << endl;
	return 0;
}
