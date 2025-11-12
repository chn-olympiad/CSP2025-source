#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define debug(x) cerr << #x << " = " << x << endl;
using namespace std;

struct Side {
	int u, v, w;
	bool operator<(const Side other) const {
		if (w != other.w) return w < other.w;
		if (u != other.u) return u < other.u;
		return v < other.v;
	}
};
struct Node {
	int v, w;
};
const int M = 1e6 + 10;
const int N = 1e4 + 10;
int n, m, k, ans;
vector<Side> side;
vector<Node> tree[N];
int C[15][N], fa[N];
bool typeA = 1;
int del_a, del_b;

int find(int u) {
	if (fa[u] != u) {
		fa[u] = find(fa[u]);
	}
	return fa[u];
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	fa[a] = b;
}
void check_side() {
	cout << "side : " << endl;
	for (auto node : side) {
		int u = node.u;
		int v = node.v;
		int w = node.w;
		cout << u << " " << v << " " << w << endl;
	}
	cout << endl;
}
void check_tree() {
	cout << "tree : " << endl;
	cout << endl;
	for (int i = 1; i <= n; ++i) {
		cout << i << ": ";
		for (Node j : tree[i]) {
			cout << "{" << j.v << ", " << j.w << "}" << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void check_fa() {
	cout << "fa : " << endl;
	for (int i = 1; i <= n; ++i) {
		cout << i << " ";
	}
	cout << endl;
}
int dfs(int u, int fat, int v) {
	for (auto to : tree[u]) {
		if (to.v == fat) continue;
		if (to.v == v) return to.w;
		int sho = dfs(to.v, u, v);
		if (sho != -1) {
			if (sho < to.w) {
				del_a = u, del_b = to.v;
			}
			return max(sho, to.w);
		}
	}
	return -1;
}

int build() {
	int ret = 0;
	for (auto node : side) {
		int u = node.u;
		int v = node.v;
		int w = node.w;
		if (find(u) != find(v)) {
			merge(u, v);
			tree[u].push_back({v, w});
			tree[v].push_back({u, w});
			ret += w;
		}
	}
	return ret;
}
void cost() {
	for (int i = 1; i <= k; ++i) {
		int need = C[i][0];
		bool use = false;
		bool st[15];
		memset(st, 0, sizeof st);
		for (int u = 1; u <= n; ++u) {
			for (int v = u + 1; v <= n; ++v) {
				int s = dfs(u, 0, v);
				int cot = 0;
				if (!use) cot += need;
				if (!st[u]) cot += C[i][u];
				if (!st[v]) cot += C[i][v];
				if (s >= cot) {
					use = true;
					st[u] = st[v] = true;
					tree[u].push_back({n+i, C[i][u]});
					tree[n+i].push_back({u, C[i][u]});
					tree[v].push_back({n+i, C[i][v]});
					tree[n+i].push_back({v, C[i][v]});
				}
			}
		}
	}
	n += k;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		side.push_back({u, v, w});
	}
	for (int i = 1; i <= k; ++i) {
		cin >> C[i][0];
		for (int j = 1; j <= n; ++j) {
			cin >> C[i][j];
		}
		if (C[i][0] != 0)
			typeA = 0;
	}
	for (int i = 1; i <= n + k; ++i) {
		fa[i] = i;
	}
	if (typeA) {
		// 性质A满足，有48分
		for (int i = 1; i <= k; ++i) {
			Side s; s.u = n + i;
			for (int j = 1; j <= n; ++j) {
				s.v = j; s.w = C[i][j];
				side.push_back(s);
			}
		}
		n += k;
		sort(side.begin(), side.end());
		ans = build();
		cout << ans << endl;
		return 0;
	}
	sort(side.begin(), side.end());
	ans = build();
	cout << ans << endl;

	return 0;
}
