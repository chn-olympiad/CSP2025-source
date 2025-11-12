#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 505, P = 998244353;

int n, m, t[N], suf[N];
i64 f[2][N][N];
std::string s;

i64 binom[N][N], fac[N];
void init(int n) {
	binom[0][0] = 1;
	for (int i = 1; i < n; i++) {
		binom[i][0] = binom[i][i] = 1;
		for (int j = 1; j < i; j++) binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % P;
	}
	fac[0] = 1;
	for (int i = 1; i < n; i++) fac[i] = fac[i - 1] * i % P;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

	init(N);
    
    std::cin >> n >> m >> s;
    for (int i = 0; i < n; i++) {
    	int x;
    	std::cin >> x;
    	t[x]++;
	}
	for (int i = n; i >= 0; i--) suf[i] = suf[i + 1] + t[i];
	
	int cur = 0;
	f[cur][0][0] = 1;
	for (int i = 0; i < n; i++) {
		memset(f[!cur], 0, sizeof f[!cur]);
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= suf[j]; k++) {
				if (f[cur][j][k] == 0) continue;
				if (s[i] == '1') {
					if (k < suf[j + 1]) (f[!cur][j][k + 1] += f[cur][j][k] % P) %= P; // Passed
					for (int u = 0; u <= t[j + 1]; u++) { // Didn't pass
						(f[!cur][j + 1][k - u] += f[cur][j][k] * (n - suf[j + 1] - (i - k)) % P * binom[t[j + 1]][u] % P * fac[u] % P * binom[k][u] % P) %= P;
					}
				} else { // Didn't pass
					if (k < suf[j + 1]) {
						for (int u = 0; u <= t[j + 1] && u <= k + 1; u++) {
							(f[!cur][j + 1][k + 1 - u] += f[cur][j][k] * binom[t[j + 1]][u] % P * fac[u] % P * binom[k + 1][u] % P) %= P;
						}
					}
					for (int u = 0; u <= t[j + 1] && u <= k; u++) {
						(f[!cur][j + 1][k - u] += f[cur][j][k] * (n - suf[j + 1] - (i - k)) % P * binom[t[j + 1]][u] % P * fac[u] % P * binom[k][u] % P) %= P;
					}
				}
			}
		}
		cur = !cur;
	}
	
	i64 ans = 0;
	for (int i = 0; i <= n - m; i++) {
		(ans += f[cur][i][suf[i + 1]] * fac[suf[i + 1]] % P) %= P;
	}
	
	std::cout << ans << "\n";

    return 0;
}