#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int MAX_N = 1e4, MAX_M = 1e6, MAX_K = 10;

struct Edge {
	int u, v, w;
	Edge(int u_, int v_, int w_): u(u_), v(v_), w(w_) {}
	bool operator<(const Edge &rhs) const {
		return w < rhs.w;
	}
};

int n, m, k;
vector<Edge> E1, E2, E3;
int c[MAX_K + 1];
int w[MAX_K + 1][MAX_N + 1];
int fa[MAX_N + MAX_K + 1];

int dsu_find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = dsu_find(fa[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		E1.emplace_back(u, v, w);
	}
	sort(E1.begin(), E1.end());
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			cin >> w[i][j];
		}
	}
	ull ans = 1e18;
	for (int S = 0; S < (1 << k); ++S) {
		ull sum = 0;
		E2.clear(), E3.clear();
		E2.reserve(k * n);
		E3.reserve(m + k * n);
		for (int i = 0; i < k; ++i) {
			if ((S >> i) & 1) {
				sum += c[i + 1];
				int u = n + i + 1;
				for (int v = 1; v <= n; ++v) {
					E2.emplace_back(u, v, w[i + 1][v]);
				}
			}
		}
		int i = 0, j = 0;
		while (i < E1.size() && j < E2.size()) {
			if (E1[i] < E2[i]) {
				E3.push_back(E1[i++]);
			} else {
				E3.push_back(E2[j++]);
			}
		}
		while (i < E1.size()) E3.push_back(E1[i++]);
		while (j < E2.size()) E3.push_back(E2[j++]);
		for (int i = 1; i <= n + k; ++i) {
			fa[i] = i;
		}
		int cnt = 0;
		for (auto e : E3) {
			if (cnt == n - 1) break;
			int x = dsu_find(e.u), y = dsu_find(e.v);
			if (x == y) continue;
			fa[x] = y;
			sum += e.w;
			++cnt;
		}
		ans = min(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}
