#include <bits/stdc++.h>
using namespace std;
const int M = 1e6+10, N = 1e5+10;
long long n, m, k, ans;
int  fa[N];

struct road {
	int u, v, w;
} a[M];

bool cmp(road x, road y) {
	return x.w < y.w;
}

int find(int x) {
	if (fa[x] != x) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

void con(int x, int y) {
	fa[y] = find(fa[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (find(a[i].u) != find(a[i].v)) {
			con(a[i].u, a[i].v);
			ans += a[i].w;
		}
	}
	cout << ans;
	return 0;
}
