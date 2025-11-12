#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

constexpr u32 Mod = 998244353;

struct Z {
	u32 x;
	
	Z(): x{0} {}
	Z(int x_): x((x_ % Mod + Mod) % Mod) {}
	Z& operator += (const Z& rhs) {
		if ((x += rhs.x) >= Mod) {
			x -= Mod;
		}
		return *this;
	}
	Z& operator -= (const Z& rhs) {
		if ((x -= rhs.x) >= Mod) {
			x += Mod;
		}
		return *this;
	}
	Z& operator *= (const Z& rhs) {
		x = 1ULL * x * rhs.x % Mod;
		return *this;
	}
	friend Z operator + (Z lhs, const Z& rhs) {
		return lhs += rhs;
	}
	friend Z operator - (Z lhs, const Z& rhs) {
		return lhs -= rhs;
	}
	friend Z operator * (Z lhs, const Z& rhs) {
		return lhs *= rhs;
	}
};

constexpr int N = 5E2 + 5;
Z C[N][N], A[N][N], fac[N];
Z f[N][N][N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	int n, m;
	std::cin >> n >> m;
	m = n - m;
	
	std::string str;
	std::cin >> str;
	
	std::vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		a[i] = str[i] - '0';
	}
	
	std::vector<int> cnt(n + 1), sum(n + 1);
	for (int i = 0; i < n; i ++) {
		int c;
		std::cin >> c;
		
		++ cnt[c];
	}
	std::partial_sum(cnt.begin(), cnt.end(), sum.begin());
	
	C[0][0] = 1;
	A[0][0] = 1;
	fac[0] = 1;
	for (int i = 1; i <= n; i ++) {
		C[i][0] = 1;
		A[i][0] = 1;
		fac[i] = fac[i - 1] * i;
		for (int j = 1; j <= i; j ++) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			A[i][j] = j * A[i - 1][j - 1] + A[i - 1][j];
		}
	}
	
	f[0][0][cnt[0]] = 1;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j <= i; j ++) {
			for (int t = 0; t <= n; t ++) {
				if (f[i][j][t].x == 0U) {
					continue;
				}
				const int s = n - i - t;
				if (a[i] == 1) {
					if (s) {
						f[i + 1][j][t] += f[i][j][t];
					}
					if (t) {
						const int all = i - (sum[j] - t);
						const int L = std::max(0, cnt[j + 1] - all);
						const int R = std::min(cnt[j + 1], n - i);
						for (int k = L; k <= R && t + k - 1 <= n; k ++) {
							const Z coef = C[all][cnt[j + 1] - k] * A[cnt[j + 1]][cnt[j + 1] - k];
							f[i + 1][j + 1][t + k - 1] += f[i][j][t] * t * coef;
						}
					}
				} else {
					const int all = i - (sum[j] - t);
					const int L = std::max(0, cnt[j + 1] - all);
					const int R = std::min(cnt[j + 1], n - i);
					for (int k = L; k <= R && t + k - 1 <= n; k ++) {
						if (k) {
							const Z coef = C[all][cnt[j + 1] - k] * A[cnt[j + 1]][cnt[j + 1] - (k - 1)];
							f[i + 1][j + 1][t + k - 1] += f[i][j][t] * coef;
						}
						if (n - sum[j + 1] - (all - (cnt[j + 1] - k)) > 0 && t + k <= n) {
							const Z coef = C[all][cnt[j + 1] - k] * A[cnt[j + 1]][cnt[j + 1] - k];
							f[i + 1][j + 1][t + k] += f[i][j][t] * coef;
						}
						if (t) {
							const Z coef = C[all][cnt[j + 1] - k] * A[cnt[j + 1]][cnt[j + 1] - k];
							f[i + 1][j + 1][t + k - 1] += f[i][j][t] * t * coef;
						}
					}
				}
			}
		}
	}
	
//	for (int i = 0; i <= n; i ++) {
//		for (int j = 0; j <= i; j ++) {
//			for (int t = 0; t <= n - i; t ++) {
//				std::cout << "f[" << i << "][" << j << "][" << t << "] = " << f[i][j][t].x << '\n';
//			}
//		}
//	}
	
	Z ans = 0;
	for (int j = 0; j <= m; j ++) {
		ans += f[n][j][0] * fac[n - sum[j]];
	}
	
	std::cout << ans.x << '\n';

	return 0;
}

