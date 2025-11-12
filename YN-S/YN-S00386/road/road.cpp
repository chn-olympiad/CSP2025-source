#include <bits/stdc++.h>
using namespace std;
int u[1000010], v[1000010], l[1000010];
int a[25][1000010];
int c[1000010];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 1; i <= m; i++) {

		scanf("%d%d%d", &u[i], &v[i], &l[i]);
	}

	sort(l + 1, l + 1 + m);

	for (int i = 1; i <= k; i++) {

		scanf("%d", &c[i]);

		for (int j = 1; j <= n; j++) {

			scanf("%d", &a[i][j]);
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {

		ans += l[i];
	}

	printf("%d\n", ans);
	return 0;
}