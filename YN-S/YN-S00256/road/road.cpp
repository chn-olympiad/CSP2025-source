#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, M = 2e6 + 5;
int n, k, m, c[N], tot, f[N], v[N];

struct node {
	int x, y, z;
} a[M];

bool cmp(node a, node b) {
	return a.z < b.z;
}

int find(int x) {
	if (f[x] != x) {
		return f[x] = find(f[x]);
	}
	return f[x];
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[i].x = u, a[i].y = v, a[i].z = w;
	}
	tot = n;
	for (int i = 1; i <= k; i++) {
		tot++;
		for (int j = 0; j <= n; j++) {
			int x;
			cin >> x;
			if (j == 0) {
				c[tot] = x;
			} else {
				a[++m].x = tot, a[m].y = j, a[m].z = x + c[tot];
			}
		}
	}
	for (int i = 1; i <= tot; i++) {
		f[i] = i;
	}
	sort(a + 1, a + m + 1, cmp);
	int ans = 0, cnt = 0;
	for (int i = 1; i <= m; i++) {
		int fx = find(a[i].x);
		int fy = find(a[i].y);

		if (fx != fy) {
			f[fx] = fy;
			if (a[i].y > n && v[a[i].y] == 1) {
				a[i].z -= c[a[i].y];
			}
			if (a[i].x > n && v[a[i].x] == 1) {
				a[i].z -= c[a[i].x];
			}
			if (a[i].x <= n && v[a[i].x] == 0)
				cnt++;
			if (a[i].y <= n && v[a[i].y] == 0)
				cnt++;
			v[a[i].x] = 1;
			v[a[i].y] = 1;
			ans += a[i].z;
			if (cnt == n) {
				break;
			}
		}
	}
	cout << ans;
	return 0;
}