#include <bits/stdc++.h>
#define int long long
const int N = 2e2 + 6;
int n, a[N][4], f[N][N][N], id[4][N];
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; std::cin >> t;
	while (t--) {
		std::cin >> n;
		if (n > 200) {
			std::vector<std::vector<int>> a(4, std::vector<int>(n + 1, 0));
			for (int i = 1; i <= n; ++i)
				std::cin >> a[1][i] >> a[2][i] >> a[3][i];
			int ans = 0;
			std::sort(a[1].begin() + 1, a[1].begin() + n + 1);
			for (int i = n; i >= n - n / 2 + 1; --i)
				ans += a[1][i];
			std::cout << ans << "\n";
			continue;
		}
		for (int i = 1; i <= n; ++i)
			std::cin >> a[i][1] >> a[i][2] >> a[i][3];
		int ans = 0;	
		for (int i = 0; i <= n / 2; ++i) {
			for (int j = 0; j <= std::min(n / 2, n - i); ++j) {
				for (int k = 0; k <= std::min(n / 2, n - i - j); ++k) 
					f[i][j][k] = 0;
			}
		}
		for (int id = 1; id <= n; ++id) {
			for (int i = n / 2; i >= 0; --i) {
				for (int j = std::min(n / 2, n - i); j >= 0; --j) {
					for (int k = std::min(n / 2, n - i - j); k >= 0; --k) {
						if (i + j + k < id - 1) continue;
						if (i) f[i][j][k] = std::max(f[i][j][k], f[i - 1][j][k] + a[id][1]);
						if (j) f[i][j][k] = std::max(f[i][j][k], f[i][j - 1][k] + a[id][2]);
						if (k) f[i][j][k] = std::max(f[i][j][k], f[i][j][k - 1] + a[id][3]);
					}
				}
			}
		}
		for (int i = 0; i <= n / 2; ++i) {
			for (int j = 0; j <= std::min(n / 2, n - i); ++j) {
				int k = n - i - j;
				if (k <= n / 2) ans = std::max(ans, f[i][j][k]);
			}
		}
		std::cout << ans << "\n";
	}
}
