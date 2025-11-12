#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 20;
int INT_INF = 0x3f3f3f3f;
long long LL_INF = 0x3f3f3f3f3f3f3f3f;
// ---------------------------
struct node {
	int u, v, w;
};
// ---------------------------
long long ans = LL_INF;
vector<node> edge, vec;
int fa[N], c[15], a[15][N];
// ---------------------------
bool cmp(node a, node b) {
	return a.w < b.w;
}

int _find(int x) {
	if (fa[x] == x) return fa[x];
	return fa[x] = _find(fa[x]);
}

void _merge(int x, int y) {
	fa[_find(x)] = _find(y);
}

void dfs(int u, int cnt, long long sum, int k, int n) {
	if (u > k) {
		vec = edge;
		for (int i = 1; i <= n + k; i++) fa[i] = i;
		sort(vec.begin(), vec.end(), cmp);
		int tmp = 0;
		for (node i : vec) {
			if (_find(i.u) == _find(i.v)) continue;
			tmp++;
			sum += i.w;
			_merge(i.u, i.v);
		}
		if (tmp < n + cnt - 1) return;
		ans = min(ans, sum);
		return;
	}
	
	for (int i = 1; i <= n; i++) edge.push_back({n + u, i, a[u][i]});
	dfs(u + 1, cnt + 1, sum + c[u], k, n);
	for (int i = 1; i <= n; i++) edge.pop_back();
	dfs(u + 1, cnt, sum, k, n);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, k, u, v, w; cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		edge.push_back({u, v, w});
	}
	bool flag = true;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i] != 0) flag = false;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0) flag = false;
		}
	}
	// ---------------------------
	if (flag) {
		cout << 0 << '\n';
		return 0;
	}
	dfs(1, 0, 0, k, n);
	// ---------------------------
	cout << ans << '\n';
	return 0;
}
