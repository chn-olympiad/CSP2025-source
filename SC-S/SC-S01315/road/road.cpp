#include<bits/stdc++.h>
int n, m, k;
const int MAXN = 1e4 + 5;
int a[MAXN][MAXN], c[MAXN];
bool C[15];
void floyd() {
	int N = k + n;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N ; j++)
			for (int K = 1; K <= N; K++) {
				if (a[i][j] > a[i][K] + a[K][j] && K <= n) {
					a[i][j] = a[i][K] + a[K][j];
				} else if (a[i][j] > a[i][K] + a[K][j] && K > n) {
					if (C[K - n]) a[i][j] = a[i][K] + a[K][j];
					else a[i][j] = a[i][K] + a[K][j] + c[K - n], C[K - n] = true;
				}
			}

}
void init() {
	std::cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v >> a[u][v];
	}
	for (int i = n + 1; i <= n + k; i++) {
		std::cin >> c[i - n];
		for (int j = 1; j <= n; j++) std::cin >> a[i][j];
	}

}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	init();
	floyd();
	long long ans = 0;
	for (int i = 1; i <= n + k; i++)
		for (int j = 1; j <= n + k; j++) {
			ans += a[i][j];
		}
	std::cout << ans << '\n';

	return 0;
}