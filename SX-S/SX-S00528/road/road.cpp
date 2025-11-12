#include <bits/stdc++.h>
using namespace std;
const long long N = 1e4+5, M = 1e6+5;
long long n, m, k, a[15][N], c[15], fa[N], ans;
bool f[15];

struct node {
	long long u, v, w;
} g[M];

bool cmp(node s1, node s2) {
	return s1.w < s2.w;
}

long long find(long long x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (long long i = 1; i <= n; i++)
		fa[i] = i;
	for (long long i = 1; i <= m; i++)
		cin >> g[i].u >> g[i].v >> g[i].w;
	for (long long i = 1; i <= k; i++) {
		cin >> c[i];
		for (long long j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	sort(g + 1, g + m + 1, cmp);
	for (long long i = 1; i <= m; i++) {
		long long x = g[i].u, y = g[i].v, z = g[i].w, sum = 1e18, id;
		x = find(x);
		y = find(y);
		if (x == y)
			continue;
		for (long long j = 1; j <= k; j++) {
			if (f[j]) {
				if (a[j][x] + a[j][y] < sum) {
					sum = a[j][x] + a[j][y];
					id = j;
				}
			} else {
				if (a[j][x] + a[j][y] + c[j] < sum) {
					sum = a[j][x] + a[j][y] + c[j];
					id = j;
				}
			}
		}
		for (long long j = 1; j <= k; j++)
			a[j][x] = min(a[j][x], a[j][y]);
		for (long long j = 1; j <= k; j++)
			a[j][y] = min(a[j][x], a[j][y]);
		fa[y] = x;
		if (z < sum)
			ans += z;
		else {
			ans += sum;
			f[id] = 1;
		}
	}
	cout << ans;
	return 0;
}
