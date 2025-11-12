//2025.11.1  zyb  T2 road
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k;

struct node {
	int u, v, w;
	friend bool operator <(node a0, node a1) {
		return a0.w < a1.w;
	}
} a[M];
int f[N];

int find(int x) {
	if (f[x] == x)
		return x;
	return f[x] = find(f[x]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for (int i = 1, x; i <= k; i++) {
		for (int j = 1; j <= n + 1; j++) {
			cin >> x;
		}
	}
	sort(a + 1, a + m + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++) {
		int fx = find(a[i].u);
		int fy = find(a[i].v);
		if (fx != fy) {
			ans += a[i].w;
			f[fx] = fy;
		}
	}
	cout << ans << '\n';
	return 0;
}