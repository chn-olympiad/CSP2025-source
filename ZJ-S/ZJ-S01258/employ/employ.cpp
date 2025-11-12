#include <bits/stdc++.h>
#define i32 int
#define i64 long long
#define u64 unsigned long long
#define For(i, l, r) for (i32 i = (l); i <= (r); i++)
using namespace std;


const i32 N = 505;
const i32 M = 1 << 18;
const i32 mod = 998244353;
i32 n, m, c[N];
char ch[N];
i32 f[M][20];
inline void add(i32& x, i32 y) {
	x += y; x = (x >= mod) ? (x - mod) : (x);
}
i32 g[105][105][105], cnt[N], C[N][N], pq[N];
inline i32 ksm(i32 x, i32 y, i32 res = 1) {
	for (; y; y >>= 1, x = 1ll * x * x % mod) if (y & 1) res = 1ll * res * x % mod;
	return res;
}
inline void trans(i32 n, i32 m, i32 c, i32 v, i32 i, i32 j, i32 k) {
	For (j, 0, min(m, c)) {
		add(g[i][j][k + c - j], ksm(C[n][m], mod, 1ll * C[n][j] * C[n - c][m - j] % mod * v % mod));
	}
}
inline void ___() {
	cin >> n >> m >> ch;
	For (i, 0, n - 1) cin >> c[i];
	if (n <= 18) {
		f[0][0] = 1; i32 u = 1 << n; u--;
		For (i, 0, u) {
			i32 cnt = __builtin_popcount(i);
			For (j, 0, cnt) if (f[i][j]) {
				For (k, 0, n - 1) {
					if (i >> k & 1) continue;
					if (cnt - j >= c[k] || ch[cnt] == '0') add(f[i | (1 << k)][j], f[i][j]);
					else add(f[i | (1 << k)][j + 1], f[i][j]);
				}
			}
		}
		i32 ans = 0; For (i, m, n) add(ans, f[u][i]);
		cout << ans << '\n';
	}
	else if (m == n) {
		bool is = 1;
		For (i, 0, n - 1) is &= c[i] >= 1, is &= ch[i] == '1';
		i32 cnt = 1; For (i, 1, n) cnt = 1ll * cnt * i % mod;
		if (is) {
			cout << cnt << '\n';
			return ;
		}
		else cout << "0\n";
	} else {
		C[0][0] = 1;
		For (i, 1, n) {
			C[i][0] = 1;
			For (j, 1, n) {
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
			}
		}
		For (i, 0, n - 1) {
			cnt[min(n + 1, c[i])]++;
		}
		pq[0] = cnt[0]; For (i, 1, n + 1) pq[i] = pq[i - 1] + cnt[i];
		g[0][0][cnt[0]] = 1;
		For (i, 0, n - 1) {
			For (j, 0, i) {
				For (k, 0, n - i) if (g[i][j][k]) {
					//1ll * f[i][j][k] * k % mod
					//n - pq[j],   i - pq[j] + k
					//cnt[j + 1]
					trans(n - pq[j], i - pq[j] + k, cnt[j + 1], 1ll * g[i][j][k] * k % mod, i + 1, j + 1, k - 1);
					// f[i + 1][j + 1][k - 1 + ]
					add(g[i + 1][j][k], 1ll * g[i][j][k] * (n - i - k) % mod);
				}
			}
		}
		i32 ans = 0;
		For (i, 0, n - m) add(ans, g[n][i][0]);
		cout << ans << '\n';
	}
}



signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	double be = clock();
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	i32 T = 1; //cin >> T;
	while (T--) ___();
	// cerr << "times: " << (clock() - be) * 1.0 / CLOCKS_PER_SEC << endl;
}