#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 20;
const int M = 1e6 +1e5 + 400;

int n, m, k;

struct Edge {
	int u, v;
	int w;
}g[M], ga[M];

bool vis[N];

int eenum;

bool cmp(Edge &a, Edge &b) {
	return a.w < b.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[eenum++] = {u, v, w};
	}
	
	sort(g, g + m, cmp);
	
//	for (int i = 0; i < m; ++i) {
//		cout << g[i].w << ' ';
//	}
//	cout << endl;
	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		if (!vis[g[i].u] || !vis[g[i].v]) {
			vis[g[i].u] = true;
			vis[g[i].v] = true;
			ans += g[i].w;
		}
	}
//	cout << ans << endl;
	
	for (int i = 0; i < k; ++i) {
		int c;
		cin >> c;
		for (int j = 0; j <= n + 1; ++j) {
			vis[j] = false;
		}
		for (int j = 0; j < m; ++j) {
			ga[j] = g[j];
		}
		for (int j = 0; j < n; ++j) {
			cin >> ga[m + j].w;
			ga[m + j].u = n + 1;
			ga[m + j].v = j + 1;
		}
		sort(ga, ga + m + n, cmp);
//		for (int j = 0; j < m + n; ++j) {
//			cout << ga[j].u << "-" << vis[ga[j].u] << vis[ga[j].v] << '-' << ga[j].v << ' ';
//		}
//		cout << endl;
		ll tans = c;
//		cout << tans << endl;
		for (int j = 0; j < m + n; ++j) {
			if (!vis[ga[j].u] || !vis[ga[j].v]) {
				vis[ga[j].u] = true;
				vis[ga[j].v] = true;
				tans += ga[j].w;
//				cout << "collect" << ga[j].w << ' ' << tans << endl;
			}
		}
		ans = min(tans, ans);
//		cout << ans << endl;
	}
	
	cout << ans << endl;
	
	return 0;
}
