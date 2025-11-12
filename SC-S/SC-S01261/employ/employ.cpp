// 二项式反演 
// 不会。 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 510;
const int mod = 998244353;
int n, m, s[maxn], c[maxn], fac[maxn], ifac[maxn];
bool flag;

inline int quickPow(int x, int p) {
	int ret = 1;
	for (; p; p >>= 1) {
		if (p & 1) {
			ret = ret * x % mod;
		}
		x = x * x % mod;
	}
	return ret;
}

void init() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	ifac[n] = quickPow(fac[n], mod - 2);
	for (int i = n - 1; i >= 1; i--) {
		ifac[i] = ifac[i + 1] * (i + 1) % mod;
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf ("%lld %lld", &n, &m);
	flag = true, init();
	for (int i = 1; i <= n; i++) {
		scanf ("%1lld", &s[i]);
		flag &= (s[i] == 1);
	}
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &c[i]);
	}
	if (flag) {
		printf ("%lld\n", fac[n]);
		return 0;
	}
}