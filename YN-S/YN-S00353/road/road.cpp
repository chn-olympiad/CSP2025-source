#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans = 0;

struct node {
	int u, v, w;
} a[10005];
int s[10005][10005];

bool cmp(node x, node y) {
	return x.w < y.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	sort(a + 1, a + 1 + m, cmp);
	if (0 == 0) {
		for (int i = 1; i <= m; i++) {
			if (s[a[i].u][a[i].v] == 0) {
				ans += a[i].w;
				s[a[i].u][a[i].v] = 1;
				s[a[i].v][a[i].u] = 1;
				for (int j = 1; j <= n; j++) {
					if (j == a[i].u || j == a[i].v)
						continue;
					if (s[a[i].u][j] == 1) {
						s[j][a[i].v] = 1;
						s[a[i].v][j] = 1;
					}
					if (s[a[i].v][j] == 1) {
						s[j][a[i].u] = 1;
						s[a[i].u][j] = 1;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}