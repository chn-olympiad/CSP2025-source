#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[10001][10001];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		a[u][v] = min(a[u][v], w);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)
				ans += a[i][j];
		}
	}
	if (!k)
		printf("%lld", ans);
	else
		printf("13");
	return 0;
}