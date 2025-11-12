#include <bits/stdc++.h>
using namespace std;
#define il inline
const int ccf = 101e4 + 10;

struct road {
	int u, v, w;
} r[ccf];
int tu[10010][10010];
int n, m, k, eu, ev, cnt = 0, fa[10010], ans = 0, kx[15];

il int f(int x) {
	if (x != fa[x])
		x = fa[x] = f(fa[x]);
	return x;
}

bool cmp(road a, road b) {
	return a.w < b.w;
}

il void change(int x, int y) {
	r[++m].u = x;
	r[m].v = y;
	r[m].w = tu[x][y];
	return;
}

il void kruskal() {
	for (int i = 1; i <= m; i++) {
		eu = f(r[i].u), ev = f(r[i].v);
		if (eu == ev)
			continue;
		ans += r[i].w;
		fa[eu] = ev;
		if (++cnt == n - 1)
			break;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> r[i].u >> r[i].v >> r[i].w;
	for (int i = 1; i <= k + 1; i++) {
		int z;
		cin >> z;
		for (int j = 1; j <= n; j++) {
			int s;
			cin >> s;
			kx[j] = s;
		}
		if (i == k + 1)
			for (int b = 2; b <= n; b++) {
				tu[1][b] = kx[1] + kx[b] + z;
				change(1, b);
			}
	}
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	sort(r + 1, r + 1 + m, cmp);
	kruskal();
	cout << ans << endl;
	return 0;
}