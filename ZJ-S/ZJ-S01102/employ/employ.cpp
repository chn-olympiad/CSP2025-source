#include<bits/stdc++.h>
using namespace std;

namespace MyNamespace {
typedef long long ll;

inline namespace MyIO {
	inline ll rd() {
		ll s = 0, w = 1;
		char ch = char(getchar());
		while (!isdigit(ch)) {
			if (ch == '-') w = -1;
			ch = char(getchar());
		}
		while (isdigit(ch)) {
			s = (s << 3) + (s << 1) + (ch ^ 48);
			ch = char(getchar());
		}
		return (s * w);
	}
	template<typename T>
	inline void wr(T x) {
		if (x < 0) x = -x, putchar('-');
		if (x > 9) wr(x / 10);
		putchar(x % 10 + 48);
		return;
	}
	inline void wrsp() {}
	template<typename T, typename... Args>
	inline void wrsp(T x, Args... args) { wr(x), putchar(' '), wrsp(args...); }
	inline void wrln() { putchar('\n'); }
	template<typename T>
	inline void wrln(T x) { wr(x), wrln(); }
	template<typename T, typename... Args>
	inline void wrln(T x, Args... args) { wrsp(x), wrln(args...); }
}

inline namespace Base {
	#define siz(A) int((A).size())
	#define bug(x) << #x << '=' << (x) << ' '

	template<typename T>
	inline T& Max(T &x, const T &y) { return x = max(x, y); }
	template<typename T>
	inline T& Min(T &x, const T &y) { return x = min(x, y); }
}

constexpr int fn = 500;
constexpr int N = fn + 10;

namespace {
	constexpr ll MO = 998244353;
	constexpr inline ll moa(ll x) { return (x >= MO ? x - MO : x); }
	constexpr inline ll moi(ll x) { return (x < 0 ? x + MO : x); }
	constexpr inline ll mo(ll x) { return moi(x % MO); }
	constexpr inline ll& Moa(ll &x) { return x = moa(x); }
	constexpr inline ll& Moi(ll &x) { return x = moi(x); }
	constexpr inline ll& Mo(ll &x) { return x = mo(x); }
	constexpr inline ll qpow(ll x, ll y) {
		Mo(x); ll k = 1;
		for (; y; y >>= 1) {
			if (y & 1) (k *= x) %= MO;
			(x *= x) %= MO;
		}
		return k;
	}
	constexpr inline ll get_inv(ll x) { return qpow(x, MO - 2); }
	inline int& Add(int &x, int y, int coe) {
		return x = (ll(x) + 1ll * y * coe) % MO;
	}
}

int n, m, a[N], b[N << 1];
int jmp[N << 1];
void proc_b() {
	for (int i = 1; i <= n; ++i) b[n + i] = i;
	b[0] = 0;
	sort(b, b + (n << 1) + 1);

	b[(n << 1) + 1] = n + 1;
	jmp[n << 1] = (n << 1) + 1;
	for (int i = (n << 1) - 1; i >= 0; --i) {
		if (b[i] == b[i + 1]) jmp[i] = jmp[i + 1];
		else jmp[i] = i + 1;
	}
	return;
}

namespace Sub0 {
	constexpr int fn = 18, fpwn = (1 << 18);
	constexpr int N = fn + 3, pwN = fpwn + 10;
	ll dp[pwN][N];
	void doit() {
		dp[0][0] = 1;
		for (int p = 0; p < (1 << n); ++p) {
			for (int j = 0; j <= n; ++j) if (dp[p][j]) {
				int cnt = 0;
				for (int i = 1; i <= n; ++i) if (p >> (i - 1) & 1) ++cnt;
				for (int i = 1; i <= n; ++i) if (~p >> (i - 1) & 1) {
					if (a[cnt + 1] == 1 && b[i] > j) Moa(dp[p | (1 << (i - 1))][j] += dp[p][j]);
					else Moa(dp[p | (1 << (i - 1))][j + 1] += dp[p][j]);
				}
			}
		}
		ll ans = 0;
		for (int j = 0; j <= n - m; ++j) Moa(ans += dp[~-(1 << n)][j]);
		wrln(ans);
		return;
	}
} // namespace Sub0

// namespace Sub1 {
// 	constexpr int fn = 100;
// 	constexpr int N = fn + 10;
// 	int f[N][N][N][N], g[N][N][N][N];
// 	void doit() {
// proc_b();
// 		f[0][0][0][0] = 1;
// 		for (int i = 0; i <= n; ++i) {
// 			for (int u = 0; u <= (n << 1); ++u) {
// 				for (int j = 0; j <= n; ++j) {
// 					for (int v = 0; v <= n; ++v) if (f[i][u][j][v]) {
// 						if (jmp[u] != u + 1 && j > 0) Add(f[i][u + 1][j - 1][v], f[i][u][j][v], j);
// 						Add(g[i][u][j][v], f[i][u][j][v], 1);
// 					}
// 				}
// 			}
// 			if (i < n) {
// 				for (int u = 0; u <= (n << 1); ++u) {
// 					for (int j = 0; j <= n; ++j) {
// 						for (int v = 0; v <= n; ++v) if (g[i][u][j][v]) {
// 							cerr bug(i) bug(u) bug(j) bug(v) bug(jmp[u]) << endl;
// 							if (a[i + 1]) Add(g[i + 1][u][j + 1][v], g[i][u][j][v], 1);
// 							else Add(f[i + 1][jmp[u]][j + 1][v + jmp[u] - u - 1], g[i][u][j][v], 1);
// 							if (v + jmp[u] - u - 1 - 1 >= 0) Add(f[i + 1][jmp[u]][j][v + jmp[u] - u - 1 - 1], g[i][u][j][v], v + jmp[u] - u - 1);
// 						}
// 					}
// 				}
// 			}
// 		}
// 		int ans = 0;
// 		for (int u = 0; u <= (n << 1); ++u) if (b[u] <= n - m) Add(ans, g[n][0][0][0], 1);
// 		wrln(ans);
// 		return;
// 	}
// } // namespace Sub1

void NamespaceMain() {
	n = rd(), m = rd();
	static char str[N];
	ignore = scanf("%s", str + 1);
	for (int i = 1; i <= n; ++i) a[i] = str[i] - '0';
	for (int i = 1; i <= n; ++i) b[i] = rd();

	Sub0::doit();
	return;
}
}
int main() {
	ignore = freopen("employ.in", "r", stdin);
	ignore = freopen("employ.out", "w", stdout);
	MyNamespace::NamespaceMain();
	return 0;
}