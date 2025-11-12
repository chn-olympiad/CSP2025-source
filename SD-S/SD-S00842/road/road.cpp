#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
int n, m, k, a[N], pa[N];
long long ans = 0;
int find_(int x) {
	if (x != pa[x]) {
		pa[x] = find_(pa[x]);
	}
	return pa[x];
}
struct Node {
	int u, v, w;
};
vector<Node> e;
bool cmp(Node a, Node b) {
	return a.w < b.w;
}
void build() {
	sort(e.begin(), e.end(), cmp);
	int t = 0;
	for (int i = 0; i < (int)e.size(); i++) {
		if (find_(e[i].u) != find_(e[i].v)) {
			pa[find_(e[i].u)] = find_(e[i].v);
			pa[find_(e[i].v)] = find_(e[i].u);
			ans += e[i].w;
			t++;
		}
		if (t == n - 1) return ;
	}
}
int main() {
	ios::sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) pa[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	for (int i = 1; i <= k; i++) {
		int c;
		cin >> c;
		if (c == 0) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i];
			}
		}
		for (int j = 1; j <= n; j++) {
			for (int l = j + 1; l <= n; l++) {
				e.push_back({j, l, a[j] + a[l]});
			}
		}
	}
	build();
	cout << ans << '\n';
	return 0;
}
