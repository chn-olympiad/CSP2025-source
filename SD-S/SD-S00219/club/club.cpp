#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
int a[100001], b[100001], c[100001], f[201][201][201], r[11]; 
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; std::cin >> t; 
	while (t--) {
		int n; std::cin >> n; 
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i] >> b[i] >> c[i]; 
		}
		if (n == 2) {
			std::cout << std::max(std::max(std::max(a[1] + b[2], a[1] + c[2]), std::max(b[1] + a[2], b[1] + c[2])), std::max(c[1] + a[2], c[1] + b[2])); 
		}
		/*
		if (n <= 200) {
			int ans = 0; 
			for (int i = 0; i <= n / 2; i++) {
				for (int j = 0; j <= n / 2; j++) {
					for (int k = 0; k <= n / 2; k++) {
						f[i][j][k] = 0; 
					}
				}
			}
			for (int i = 0; i <= n / 2; i++) {
				for (int j = 0; j <= n / 2; j++) {
					for (int k = 0; k <= n / 2 && i + j + k <= n; k++) {
						int l = i + j + k, t1 = 0, t2 = 0, t3 = 0, t = 0; 
						if (l == 0) continue; 
						if (i > 0) t1 = f[i - 1][j][k] + a[i]; 
						if (j > 0) t2 = f[i][j - 1][k] + b[i]; 
						if (k > 0) t3 = f[i][j][k - 1] + c[i];
						/*
						if (i > 0 && j > 0 && k > 0 && t == f[i][j - 1][k] && f[i - 1][j][k] == f[i][j - 1][k] && f[i][j - 1][k] == f[i][j][k - 1]) {
							f[i][j][k] = t + std::max(c[l], std::max(a[l], b[l])); 
						}
						else if (i > 0 && j > 0 && t == f[i - 1][j][k] && f[i - 1][j][k] == f[i][j - 1][k]) {
							f[i][j][k] = t + std::max(a[l], b[l]); 
						}
						else if (i > 0 && k > 0 && t == f[i][j][k - 1] && f[i - 1][j][k] == f[i][j][k - 1]) {
							f[i][j][k] = t + std::max(a[l], c[l]); 
						} 
						else if (j > 0 && k > 0 && t == f[i][j][k - 1] && f[i][j - 1][k] == f[i][j][k - 1]) {
							f[i][j][k] = t + std::max(c[l], b[l]); 
						}
						else {
							if (i > 0 && t == f[i - 1][j][k]) f[i][j][k] = t + a[l]; 
							else if (j > 0 && t == f[i][j - 1][k]) f[i][j][k] = t + b[l]; 
							else if (k > 0 && t == f[i][j][k - 1]) f[i][j][k] = t + c[l]; 
						}
						f[i][j][k] = std::max(t1, std::max(t2, t3)); 
						std::cout << "\n" << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << "\n"; 
						if (l == n) ans = std::max(ans, f[i][j][k]); 
					}
				}
			}
			std::cout << ans << '\n'; 
		}*/
	} 
	return 0;
}

/*
int f[100001], d[4]; 
struct aa {
	int a, b, c; 
	bool operator<(const aa& x) const {
		int tmp1 = std::max(std::max(a, b), c); 
		int tmp2 = std::max(std::max(x.a, x.b), x.c);
		return tmp1 > tmp2; 
	}
}a[100001];
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	int t; std::cin >> t; 
	while (t--) {
		int n; std::cin >> n; 
		for (int i = 1; i <= n; i++) std::cin >> a[i].a >> a[i].b >> a[i].c; 
		memset(f, 0, sizeof(f)), memset(d, 0, sizeof(d)); 
		std::sort(a + 1, a + n + 1); 
		for (int i = 1; i <= n; i++) {
			int t = 0, flag = 0;
			if (d[1] < n / 2) t = std::max(a[i].a + f[i - 1], t); 
			if (d[2] < n / 2) t = std::max(a[i].b + f[i - 1], t); 
			if (d[3] < n / 2) t = std::max(a[i].c + f[i - 1], t); 
			if (t == a[i].a + f[i - 1]) flag = 1; 
			if (t == a[i].b + f[i - 1]) flag = 2; 
			if (t == a[i].c + f[i - 1]) flag = 3; 
			f[i] = t, d[flag]++; 
		}
		std::cout << f[n]; 
	} 
	return 0;
}*/

