#include <bits/stdc++.h>
using namespace std;

struct li {
	int to, val;
	bool operator <(li a2) const {
		return val > a2.val;
	}
};
int a[1001], ans = 0;
bool d[1001];
priority_queue<li>Q[1001];

int dfs(int x) {
	d[x] = true;

	while (!Q[x].empty() && (!d[Q[x].top().to])) {
		dfs(Q[x].top().to);
		ans += Q[x].top().val;
		Q[x].pop();
	}

	return ans;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {

		int u, v, w;
		cin >> u >> v >> w;
		Q[u].push({v, w});
		Q[v].push({u, w});
	}

	for (int i = 1; i <= k; i++) {

		int q;
		cin >> q;

		for (int i = 1; i <= n; i++) {

			cin >> a[i];

			for (int j = 1; j < i; i++) {

				Q[i].push({j, q + a[j] + a[i]});
				Q[j].push({i, q + a[j] + a[i]});
			}
		}
	}

	cout << dfs(1);
	return 0;
}