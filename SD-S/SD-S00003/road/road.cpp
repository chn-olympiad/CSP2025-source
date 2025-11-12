#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2000010;

int n, m, k;
array<int, 3> edge[N], Edge[N];
int p[N];
int dis[12][20010], c[N];

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		
		edge[i] = {u, v, w};
	}
	
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			cin >> dis[i][j];
		}
	} 
	
	for (int i = 1; i <= n; ++i) p[i] = i;
	
	sort(edge + 1, edge + 1 + m, [&](array<int, 3> a, array<int, 3> b) {
		return a[2] < b[2];
	});
	
	int cnt = 0;
	for (int i = 1; i <= m; ++i) {
		int u = edge[i][0], v = edge[i][1], w = edge[i][2];
		
		int fu = find(u), fv = find(v);

		if (fu != fv) {
			p[fu] = fv;
			++cnt;
			Edge[cnt] = {u, v, w};
//			cout << u << ' ' << v << ' ' << w << endl;
		}
	}
	
	ll ans = 1ll << 60;
	for (int i = 0; i < (1 << k); ++i) {
		ll res = 0;
		
		int idx = 0;
		for (int j = 1; j < n; ++j) edge[++idx] = Edge[j];

		for (int j = 0; j < k; ++j) {
			if ((i >> j) & 1) {
				res += 1ll * c[j + 1];
				for (int q = 1; q <= n; ++q)
					edge[++idx] = {n + j + 1, q, dis[j + 1][q]};
			}
		}
		
//		cout << res << endl;
		
		sort(edge + 1, edge + 1 + idx, [&](array<int, 3> a, array<int, 3> b) {
			return a[2] < b[2];
		});
		for (int j = 1; j <= n + k; ++j) p[j] = j;
		
		for (int j = 1; j <= idx; ++j) {
			int u = edge[j][0], v = edge[j][1], w = edge[j][2];
			
			int fu = find(u), fv = find(v);
	
			if (fu != fv) {
				p[fu] = fv;
				res += 1ll * w;
			}
		}

//		cout << i << ' ' << res 	<< endl;
		ans = min(ans, res);
	}
	
	cout << ans << endl;

	return 0;
}

