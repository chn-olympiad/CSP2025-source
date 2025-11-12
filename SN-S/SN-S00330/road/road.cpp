#include <bits/stdc++.h>

using namespace std;
int n, m, k;
array<int, 25> c;
array<int, 10025> dsu;

int find(int x) {
	if (dsu[x] == x) {
		return x;
	} else {
		return dsu[x] = find(dsu[x]);
	}
}

void merge(int x, int y) {
	dsu[find(x)] = find(y);
}

struct edge {
	int u, v, w;

	edge(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
};
vector<edge> org_e, eff_e;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;

		org_e.emplace_back(u, v, w);
	}

	sort(org_e.begin(), org_e.end(), [](auto x, auto y) -> bool {
		return x.w < y.w;
	});

	for (int i = 1; i <= n; ++i) {
		dsu[i] = i;
	}

	long long ans = 0;
	{
		int cnt = 0;
		for (edge i : org_e) {
			int u = i.u, v = i.v, w = i.w;

			if (find(u) != find(v)) {
				merge(u, v);
				ans += w;
				eff_e.push_back(i);

				cnt++;
				if (cnt == n - 1) {
					break;
				}
			}
		}
	}
	
//	cerr << clock() << "\n";

	vector<vector<edge>> e(k + 1);
	e[k] = eff_e;
	for (int i = 0; i < k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			int x;
			cin >> x;
			e[i].emplace_back(n + i + 1, j, x);
		}

		sort(e[i].begin(), e[i].end(), [](auto x, auto y) -> bool {
			return x.w < y.w;
		});
	}

	for (int state = 1; state < (1 << k); ++state) {
		for (int i = 1; i <= n + k; ++i) {
			dsu[i] = i;
		}

		long long term = 0;
		vector<int> all_1;
		int cnt_e = e[k].size();
		for (int i = 0; i < k; ++i) {
			if ((state >> i) & 1) {
				term += c[i];
				cnt_e += e[i].size();
				all_1.push_back(i);
			}
		}
		all_1.push_back(k);

		vector<edge> all_e;
		{
			vector<int> ptrs(k + 1, 0);
			while (all_e.size() < cnt_e) {
				int idx = -1;
				edge min_e(0, 0, 0);
				for (int i : all_1) {
					if (ptrs[i] < e[i].size()) {
						if (idx == -1 || e[i][ptrs[i]].w < min_e.w) {
							idx = i;
							min_e = e[i][ptrs[i]];
						}
					}
				}

				ptrs[idx]++;
				all_e.push_back(min_e);
			}
		}

//		for (edge i : all_e) {
//			int u = i.u, v = i.v, w = i.w;
//
//			if (state == 1) {
//				cerr << u << " " << v << " " << w << "\n";
//			}
//		}

		for (edge i : all_e) {
			int u = i.u, v = i.v, w = i.w;

			if (find(u) != find(v)) {
				term += w;
				merge(u, v);
			}
		}

		ans = min(ans, term);
	}
	cout << ans;
//	cerr << clock();
	return 0;
}
