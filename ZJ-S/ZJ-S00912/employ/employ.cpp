// 沒有別的選擇了，我必須贏
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510;
const int mod = 998244353;

int n, m, c[N];
char s[N];
bool b[N];

ll qpow(ll a, int b) {
	ll res = 1;
	a %= mod;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

	ll fac[N];

inline void solveA() {
	int t = n;
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) {
			t--;
		}
	}
	if (t < m) {
		printf("0\n");
		return;
	}
	printf("%lld\n", fac[n] % mod);
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s + 1);
	int cnt = 0, f = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		if (!c[i]) f = 0;
		b[i] = s[i] - '0';
		if (b[i]) {
			cnt++;
		}
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	if (cnt < m) {
		printf("0\n");
		return 0;
	}
	if (cnt == n) {
		solveA();
	}
	if (m == n) {
		if (cnt == n && f) printf("%lld\n", fac[n] % mod);
		else printf("0\n");
	}
	printf("0\n");
}
