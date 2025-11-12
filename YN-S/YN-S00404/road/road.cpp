#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4 + 5;
const int M = 2e6 + 5;
const int K = 15;
ll n, m, k, tmp, flag1, flag2, ans = 1e18, dis[N + K], vis[N + K], res, c[N], a[K][N];

struct node {
	ll v, w;
};
vector<node>e[N + K];

void prim(int flag) {
	priority_queue<pair<ll, ll>>q;
	for (int i = 1; i <= n + k; i++) {
		dis[i] = 1e18, vis[i] = 0;
	}
	dis[1] = 0;
	q.push({0, 1});
	while (!q.empty()) {
		int x = q.top().second;
		q.pop();
		if (vis[x])
			continue;
		vis[x] = 1;
		res += dis[x];
		for (int i = 0; i < e[x].size(); i++) {
			int v = e[x][i].v;
			int w = e[x][i].w;
			if (v > n && (flag & (1 << (v - n - 1))) == 0)
				continue;
			if (dis[v] > w) {
				dis[v] = w;
				q.push({-dis[v], v});
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		e[x].push_back({y, z});
		e[y].push_back({x, z});
	}
	flag1 = 1;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i] != 0)
			flag1 = 0;
		flag2 = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0)
				flag2 = 1;
		}
		if (flag2 == 0)
			flag1 = 0;
	}
	if (flag1 == 1) {
		for (int i = 1; i <= k; i++) {
			int flag = 0;
			for (int j = 1; j <= n; j++) {
				if (a[i][j] == 0) {
					if (flag == 0) {
						flag = j;
						for (int t = 1; t <= n; t++) {
							e[j].push_back({t, a[i][t]});
							e[t].push_back({j, a[i][t]});
						}
					} else {
						e[j].push_back({flag, 0});
						e[flag].push_back({j, 0});
					}
				}
			}
		}
		prim(0);
		cout << res;
		return 0;
	} else {
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				e[i + n].push_back({j, a[i][j]});
				e[j].push_back({i + n, a[i][j]});
			}
		}
	}
	const int maxn = (1 << k) - 1;
	for (int i = 0; i <= maxn; i++) {
		res = 0;
		for (int j = 1; j <= k; j++) {
			if (i & (1 << (j - 1))) {
				res += c[j];
			}
		}
		prim(i);
		ans = min(ans, res);
	}
	cout << ans ;
	return 0;
}