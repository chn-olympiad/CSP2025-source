#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 10010, M = 1e6 + 1e5 + 10;
int n, m, k, c[20], a[20][N], d[N];
struct Node {
	int x, y, z;
	bool operator< (const Node& b) const {
		return z < b.z;
	}
}edges[M], lst[M];

int p[N + 100];
int getfa(int x) {
	if (p[x] == x) return x;
	return p[x] = getfa(p[x]);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &edges[i].x, &edges[i].y, &edges[i].z);
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		d[i] = 1;
	}
	int cc = 0;
	sort(edges + 1, edges + m + 1);
	for (int i = 1; i <= m; i++) {
		int px = getfa(edges[i].x), py = getfa(edges[i].y);
		if (px == py) continue;
		if (d[px] > d[py]) swap(px, py);
		p[px] = py;
		d[py] += d[px];
		lst[++cc] = edges[i];
	}
	LL ans = 1e18;
	for (int cur = 0; cur < (1 << k); cur++) {
		int cnt = n - 1;
		LL sum = 0;
		for (int i = 1; i <= n - 1; i++) edges[i] = lst[i];
		for (int j = 0; j < k; j++) if (cur >> j & 1) {
			for (int k = 1; k <= n; k++) {
				edges[++cnt] = {j + n + 1, k, a[j][k]};
			}
			sum += c[j];
		}
		sort(edges + 1, edges + cnt + 1);
		for (int i = 1; i <= n + k; i++) {
			p[i] = i;
			d[i] = 1;
		}
		for (int i = 1; i <= cnt; i++) {
			int px = getfa(edges[i].x), py = getfa(edges[i].y);
			if (px == py) continue;
			if (d[px] > d[py]) swap(px, py);
			p[px] = py;
			d[py] += d[px];
			sum += edges[i].z;
		}
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}
