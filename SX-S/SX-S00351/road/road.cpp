#include <bits/stdc++.h>
using namespace std;
long long ans = -1e18;
int n, m, k;
int vis[100009];

struct node {
	int to, val;
};
vector<node>e[10009];

void dfs(int u, long long sum, int mmm) {
	if (mmm == n + 1) {
		ans = max(sum, ans);
		return;
	}
	for (auto tmp : e[u]) {
		if (!vis[tmp.to]) {
			vis[tmp.to] = 1;
			dfs(tmp.to, sum + tmp.val, mmm + 1);
			vis[tmp.to] = 0;
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int f, t, v;
		e[f].push_back({t, v});
		e[t].push_back({f, v});
	}
	dfs(1, 0, 1);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}