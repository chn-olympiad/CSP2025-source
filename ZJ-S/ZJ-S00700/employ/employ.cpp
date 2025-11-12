#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 5e2 + 10;
const int mod = 998244353;

inline int add(int a, int b) { return a += b, a >= mod ? a - mod : a; }
inline int sub(int a, int b) { return a -= b, a < 0 ? a + mod : a; }
inline int mul(int a, int b) { return (unsigned long long)a * b % mod; }
inline void toadd(int &a, int b) { a = add(a, b); }

int n, m;
char s[N];
int c[N];

namespace sub1 {

bool check() {
	return n <= 18;
}

int f[1 << 18][20];

void solve() {
	f[0][0] = 1;
	for (unsigned s = 0; s < 1u << n; ++s) {
		int x = __builtin_popcount(s) + 1;
		for (int ct = 0; ct <= n; ++ct)
			if (f[s][ct]) {
				for (int i = 1; i <= n; ++i)
					if (~s & 1u << (i - 1)) {
						toadd(f[s | 1 << (i - 1)][ct + (::s[x] == '0' || c[i] <= ct)], f[s][ct]);
					}
			}
	}
	int ans = 0;
	for (int i = 0; i <= n - m; ++i)
		toadd(ans, f[(1 << n) - 1][i]);
	printf("%d", ans);
}

}

namespace sub2 {

bool check() {
	return m == 1;
}

int ct[N];

void solve() {
	int facn = 1;
	for (int i = 1; i <= n; ++i) facn = mul(facn, i);
	for (int i = 1; i <= n; ++i) {
		++ct[c[i]];
	}
	for (int i = 1; i <= n; ++i) {
		ct[i] += ct[i - 1];
	}
	int ans = 1, k = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '1') {
			int num = ct[i - 1] - k;
			if (num <= 0) {
				ans = 0;
				break;
			}
			ans = mul(ans, num);
			++k;
		}
	}
	for (int i = 1; i <= n - k; ++i)
		ans = mul(ans, i);
	printf("%d", sub(facn, ans));
}

}

namespace sub3 {

bool check() {
	return m == n;
}

void solve() {
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		ans = mul(ans, i);
		if (c[i] == 0) {
			puts("0");
			return;
		}
		if (s[i] == '0') {
			puts("0");
			return;
		}
	}
	printf("%d", ans);
}

}

namespace sub4 {

bool check() {
	return true;
}

int f[N][N][N], ct[N], pre[N];

void solve() {
	int x = 1;
	for (int i = 1, k = 1; i <= n; ++i)
		if (s[i] == '0')
			x = mul(x, k++);
	for (int i = 1; i <= n; ++i) {
		++ct[c[i]];
	}
	pre[0] = ct[0];
	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + ct[i];
	}
	for (int i = 0; i <= n - m; ++i) {
		int cnt = 0;
		for (int j = 1; j <= n; ++j) cnt += c[j] > i;
		f[n][i][cnt] = x;
	}
	for (int i = n; i; --i)
		for (int j = 0; j <= n; ++j)
			for (int k = 0; k <= n; ++k) {
				if (!f[i][j][k]) continue;
				if (s[i] == '1') {
					if (k) {
						toadd(f[i - 1][j][k - 1], mul(k, f[i][j][k]));
					}
					if (j) {
						toadd(f[i - 1][j - 1][k + ct[j]], mul(pre[j], f[i][j][k]));
					}
				} else {
					if (j) {
						toadd(f[i - 1][j - 1][k + ct[j]], f[i][j][k]);
					}
				}
			}
	int ans = 0;
	for (int i = 0; i <= n; ++i)
		toadd(ans, f[0][0][i]);
	printf("%d", ans);
}

}

int main() {
#ifndef XuYueming
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
#endif
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}
	sort(c + 1, c + n + 1);
#ifndef XuYueming
	if (sub1::check()) return sub1::solve(), 0;
	if (sub2::check()) return sub2::solve(), 0;
	if (sub3::check()) return sub3::solve(), 0;
#endif
	if (sub4::check()) return sub4::solve(), 0;
	throw;
	return 0;
}

