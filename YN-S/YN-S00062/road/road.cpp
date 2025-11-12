#include <bits/stdc++.h>
using namespace std;
#define int long long

struct d {
	int u, v, w;
};
const int N = 1e6 + 5;
vector<d>e;
int fa[N];

int find(int x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) {
		fa[x] = y;
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		e.push_back({x, y, z});
	}
	int ans = 0, cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (find(u) != find(v)) {
			merge(u, v);
			ans += w;
			cnt++;
		}
	}
	if (cnt == n - 1)
		cout << ans << endl;
	return 0;
}