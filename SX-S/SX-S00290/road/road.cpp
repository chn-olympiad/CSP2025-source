#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int u[1000005], v[1000005], w[1000005];
long long ans = 0;
int c[15], a[15][10005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		ans += w[i];
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", a[i][j]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}