#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4 + 5;
const int M = 1e6 + 5;

int n, m, k, c[N], fa[N], a[10][N];

ll ans = 1e18;

vector<pair<pair<int, int>, int>> G0, G;

inline int _find(int u) {
	return (fa[u] == u) ? u : (fa[u] = _find(fa[u]));
}

inline void merge(int u, int v) {
	fa[_find(u)] = _find(v);
}

int main() {
	assert(freopen("road.in", "r", stdin));
	assert(freopen("road.out", "w", stdout));
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> k;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		G0.emplace_back(make_pair(u, v), w);
	}
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	}
	sort(G0.begin(), G0.end(), [](auto u, auto v) {
		return u.second < v.second;
	});
	for (auto p: G0) {
		int u = p.first.first, v = p.first.second, w = p.second;
		if (_find(u) != _find(v)) {
			merge(u, v);
			G.emplace_back(make_pair(u, v), w);
		}
	}
	for (int i = 0; i < k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			G.emplace_back(make_pair(i + n + 1, j), a[i][j]);
		}
	}
	sort(G.begin(), G.end(), [](auto u, auto v) {
		return u.second < v.second;
	});
	for (int i = 0; i < (1 << k); ++i) {
		for (int j = 1; j <= n + k; ++j) {
			fa[j] = j;
		}
		auto check = [&](int u) {
			if (u > n) {
				return (i >> (u - n - 1)) & 1;
			}
			return 1;
		};
		ll sum = 0;
		for (int j = 0; j < k; ++j) {
			if ((i >> j) & 1) {
				sum += c[j];
			}
		}
		for (auto p: G) {
			int u = p.first.first, v = p.first.second, w = p.second;
			if (check(u) && check(v) && _find(u) != _find(v)) {
				merge(u, v);
				sum += w;
			}
		}
		ans = min(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}