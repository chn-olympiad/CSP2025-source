#include <bits/stdc++.h>
using namespace std;
const int N = 1000001, M = 10001;
int n, m, k, u, v, w, c[11][N], a[M][M], dp[M];
long long ans;
vector<int> v;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	if (k == 0) {
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			if (a[u][v] == 0 || a[v][u] = 0) {
				a[u][v] = w;
				a[v][u] = w;
			} else {
				a[u][v] = max(a[u][v], w);
				a[v][u] = max(a[v][u], w);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (j == i)
					continue;
			}
		}
	}

	return 0;
}
