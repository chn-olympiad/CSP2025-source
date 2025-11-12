#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5;
vector<pair<int, int>>g[N];
int fa[N];
int c[N];
vector<pair<int, int>>h[N];
int n, m, k;
vector<int>hg;

int find(int x) {
	if (x == fa[x])
		return x;
	else
		return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	if (find(x) != find(y)) {
		fa[find(x)] = find(y);
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
//g[u].push_back({v,w});
//	g[v].push_back({u,w});
		h[w].push_back({u, v});
		hg.push_back(w);
	}
	int tot = n;
	for (int i = 1; i <= k; i++) {
		int kk;
		cin >> kk;
		tot++;
		for (int i = 1; i <= n; i++) {
			int ww;
			cin >> ww;
			//	g[tot].push_back({i,ww+kk});
			//	g[i].push_back({tot,ww+kk});
			h[ww + kk].push_back({tot, i});
			hg.push_back(ww + kk);
		}
	}
	sort(hg.begin(), hg.end());
	int ans = 0;


	for (auto t : hg) {
		bool hhh = 0;
		for (auto v : h[t]) {
			if (find(v.first) != find(v.second)) {
				ans += t;
				merge(v.first, v.second);
			}
			bool f = 0;
			for (int i = 1; i < n; i++) {
				if (find(i) != find(i + 1)) {
					f = 1;
					//	cout << i << endl;
				}
			}
			//	cout << ans << endl;
			if (!f) {
				hhh = 1;
				break;
			}
		}
		if (hhh)
			break;
	}
	cout << ans;


	return 0;
}