#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 20;

struct road {
	int v, val;
};

struct c {
	int u, v, w, need;
};

struct roads {
	int u, v, val;
	friend operator <(roads a, roads b) {
		return a.val > b.val;
	}
};

int n, m, k, ans = LLONG_MAX;
vector<c> chan[N];
vector<road> g[N];
int pay[11];
priority_queue<roads> q;
int fa[N];

int find(int x) {
	if (fa[x] == x)
		return x;
	fa[x] = find(fa[x]);
	return fa[x];
}

void dfs(int dep, int pay[11], int k) {
	if (dep < k) {
		pay[dep] ^= 1;
		dfs(dep + 1, pay, k);
		pay[dep] ^= 1;
		dfs(dep + 1, pay, k);
	}
	if (dep == k) {
		while (!q.empty())
			q.pop();
		int tmp = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (auto way : g[i]) {
				q.push({i, way.v, way.val});
			}
		}

		for (int i = 1; i <= n + k; i++) {
			fa[i] = i;
		}
		for (int i = 1; i <= k; i++) {
			if (pay[i]) {
				tmp += chan[i][0].need;
				for (auto way : chan[i]) {
					q.push({way.u, way.v, way.w});
				}
			} else {
				for (auto way : chan[i]) {
					q.push({way.u, way.v, way.w + way.need});
				}
			}
		}
		while (cnt < n) {
			int u = q.top().u, v = q.top().v;
			if (find(u) != find(v)) {
				fa[fa[u]] = fa[v];
				tmp += q.top().val;
				if (u <= n && v <= n)
					cnt++;
			}
			q.pop();
			if (cnt == n - 1) {
				ans = min(ans, cnt);
				break;
			}

		}
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++) {
		int need;
		cin >> need;
		for (int j = 1; j <= n; j++) {
			int w;
			cin >> w;
			chan[i].push_back({i + n, j, w, need});
			chan[i].push_back({j, i + n, w, need});
		}
	}
	dfs(1, pay, k);
	cout << ans;

	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4