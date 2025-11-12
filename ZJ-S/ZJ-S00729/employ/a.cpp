#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector < int >;
using pii = pair < int, int >;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define qio() cin.tie() -> sync_with_stdio(0)
#define L(i, l, r) for (int i = l; i <= r; i++)
#define R(i, r, l) for (int i = r; i >= l; i--)
#define popc __builtin_popcount

const int N = 505, mod = 998244353;

inline int jia(int x, int y) {
	return x + y >= mod ? x + y - mod : x + y;
}
inline void add(int& x, int y) {
	x = x + y >= mod ? x + y - mod : x + y;
}
inline int jian(int x, int y) {
	return x - y < 0 ? x - y + mod : x - y;
}
int power(int x, int y, int res = 1) {
	for (; y; y >>= 1, x = (ll)x * x % mod) {
		if (y & 1) res = (ll)res * x % mod;
	}
	return res;
}

int n, m, c[N];
string test;

int fac[N], inv[N];
void initfac() {
	fac[0] = 1;
	L(i, 1, n) fac[i] = (ll)fac[i - 1] * i % mod;
	inv[n] = power(fac[n], mod - 2);
	R(i, n - 1, 1) inv[i] = ll(i + 1) * inv[i + 1] % mod;
}

// 有感觉, 但不会, 有点慌 - 17:48

namespace S15 {
	const int M = 18;
	int dp[1 << M][M];
	void solve() {
		L(i, 1, n) c[i - 1] = c[i];
		dp[0][0] = 1;
		L(s, 0, (1 << n) - 1) {
			L(fail, 0, popc(s)) {
				L(i, 0, n - 1) {
					if (s >> i & 1) continue;
					if (fail >= c[i] || test[popc(s) + 1] == '0') add(dp[s | 1 << i][fail + 1], dp[s][fail]);
					else add(dp[s | 1 << i][fail], dp[s][fail]);
				}
			}
		}
		int ans = 0;
		L(i, 0, n - m) add(ans, dp[(1 << n) - 1][i]);
		cout << ans << '\n';
		exit(0);
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> test;
	test = " " + test;
	L(i, 1, n) {
		cin >> c[i];
	}
	initfac();
	if (m == n) {
		bool f = 1;
		L(i, 1, n) f &= test[i] == '1' && c[i] > 0;
		cout << (!f ? 0 : fac[n]) << '\n';
		return 0;
	} // 4pts
	sort(c + 1, c + n + 1);
	if (n <= 18) {
		S15::solve();
	} // 20pts
	cout << "0\n";
	return 0;
}
