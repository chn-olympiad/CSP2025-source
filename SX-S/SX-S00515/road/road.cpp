#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5, M = 1e6+5;

struct Edge {
	int u, v, w, nxt;
} e[M << 4];
int head[M << 4], cnt;

inline void add(int u, int v, int w) {
	cnt++;
	e[cnt] = {u, v, w, head[u]};
	head[u] = cnt;
}
int n, m, k, ans = 1e9, vis[N];

inline void dfs(int x, int sum, int tot) {
	if (sum >= ans)
		return;
	if (tot == n) {
		ans = min(ans, sum);
		//	cout << ans << endl;
		return;
	}
	for (int i = head[x], v, w; i; i = e[i].nxt) {
		v = e[i].v, w = e[i].w;
		if (vis[v] == 1)
			continue;
		vis[v] = 1;
		sum += w;
		tot++;
		dfs(v, sum, tot);
		tot--;
		sum -= w;
		vis[v] = 0;
	}

}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1, c, arr[N]; i <= k; i++) {
		cin >> c;
		for (int j = 1; j <= n; j++) {
			cin >> arr[j];
		}
		for (int j = 1; j < n; j++) {
			for (int o = j + 1; o <= n; o++) {
				add(j, o, c + arr[j] + arr[o]);
				add(o, j, c + arr[j] + arr[o]);
			}
		}
	}
	vis[1] = 1;
	for (int i = 1; i <= n; i++) {
		dfs(i, 0, 1);

	}
	cout << ans;

	return 0;
}
