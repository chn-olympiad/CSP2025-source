#include <bits/stdc++.h>
using namespace std;

long long ans;
const int N = 1e6 + 5;
const int N1 = 1e16 + 5;
const int N2 = 1e4 + 5;
struct node {
	int u, v, w;
} g[1000005];
int n, m, k;
bool vis[N2];
int gk[15][10005];

void dfs(int dep, long long sum, int point) {
	if (point == n) {
		ans = min(ans, sum);
	}
	if (dep > m || sum > ans) {
		return;
	}
	int p1 = g[dep].u, p2 = g[dep].v;
	if ((!vis[p1]) && (!vis[p2])) {
		vis[p1] = 1, vis[p2] = 1;
		dfs(dep + 1, sum + g[dep].w, point + 2);
		vis[p1] = 0, vis[p2] = 0;
		dfs(dep + 1, sum, point);
	} else if (vis[p1] && (!vis[p2])) {
		vis[p2] = 1;
		dfs(dep + 1, sum + g[dep].w, point + 1);
		vis[p2] = 0;
		dfs(dep + 1, sum, point);
	} else if (vis[p2] && (!vis[p1])) {
		vis[p1] = 1;
		dfs(dep + 1, sum + g[dep].w, point + 1);
		vis[p1] = 0;
		dfs(dep + 1, sum, point);
	}
}

int main() {
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> g[i].u >> g[i].v >> g[i].w;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> gk[i][j];
		}
	}
	ans = N1;
	dfs(1, 0, 0);
	cout << ans;

	return 0;
}
/*Ren5Jie4Di4Ling5%*/