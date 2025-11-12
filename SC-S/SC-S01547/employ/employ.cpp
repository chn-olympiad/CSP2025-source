// Go in my style.
// Not afraid to dark.
// Beat.

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e2, mod = 998244353;
int n, m, c[N + 5];
char s[N + 5];

#define popc(x) __builtin_popcount(x)

namespace sol1 {
	const int B = 18;
	int f[1 << B][B + 5];
	inline void sol() {
		f[0][0] = 1;
		for (int i = 0; i < n; ++i) c[i] = c[i + 1];
		for (int i = 0; i < (1 << n); ++i)
			for (int j = 0; j <= n; ++j)
				if (f[i][j]) {
					for (int k = 0; k < n; ++k)
						if (!(i >> k & 1)) {
							int w = f[i][j];
							if (j >= c[k] || s[popc(i) + 1] == '0') (f[i | (1 << k)][j + 1] += w) %= mod;
							else (f[i | (1 << k)][j] += w) %= mod;
						}
				}
		int ans = 0;
		for (int i = 0; i <= n - m; ++i)
			ans += f[(1 << n) - 1][i];
		printf("%lld\n", ans % mod);
	}
}
namespace sol2 {
	int ton[N + 5];
	inline void sol() {
		int ans = 1, res = 1, cnt = 0;
		for (int i = 1; i <= n; ++i) ans = ans * i % mod, ton[c[i]]++;
		for (int i = 1; i <= n; ++i) ton[i] += ton[i - 1];
		
		for (int i = 1; i <= n; ++i)
			if (s[i] == '1') {
				res = res * (ton[i - 1] - cnt) % mod;
				++cnt;
			}
		for (int i = 1; i <= n - cnt; ++i) res = res * i % mod;
		printf("%lld\n", (ans + mod - res) % mod);
	}
}

//namespace sol3 {
//	const int B = 18;
//	inline bool Check() {
//		int cnt = 0;
//		for (int i = 1; i <= n; ++i)
//			if (s[i] == '1') ++cnt;
//		return cnt <= B;
//	}
//	int cnt, pos[B], f[B + 5][B + 5];
//	int upw[N + 5], dww[N + 5];
//	inline void sol() {
//		for (int i = 1; i <= n; ++i)
//			if (s[i] == '1') pos[cnt++] = i;
//		for (int i = 0; i < (1 << cnt); ++i)
//			if (popc(i) >= m) {
//				int prec = 0;
//				vector<int> ds; ds.emplace_back(n); dww[n] = n - cnt;
//				for (int j = 0; j < cnt; ++j) {
//					int prx = prec + pos[j] - 1 - j;
//					ds.emplace_back(prx);
//					if (i >> j & 1) ++upw[prx];
//					else ++dww[prx], ++prec;
//				}
//				sort(ds.begin(), ds.end());
//				ds.erase(unique(ds.begin(), ds.end()), ds.end());
//				
//			}
//	}
//}

namespace sol4 {
	inline void sol() {
		for (int i = 1; i <= n; ++i) if (c[i] == 0 || s[i] == '0') {
			printf("0\n");
			return ;
		}
		int ans = 1;
		for (int i = 1; i <= n; ++i) ans = ans * i % mod;
		printf("%lld\n", ans);
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%lld%lld\n%s", &n, &m, s + 1);
	for (int i = 1; i <= n; ++i) scanf("%lld", &c[i]);
	
	if (n <= 18) sol1::sol();
	else
	if (m == 1) sol2::sol();
	else
	if (m == n) sol4::sol();
//	else
//	if (sol3::Check()) sol3::sol();
	
    return 0;
}