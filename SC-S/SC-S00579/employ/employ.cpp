#include <bits/stdc++.h>
using namespace std;
constexpr int N = 500 + 15;

int n, m;
ll ans;
char s[N];
int c[N], a[N];
ll fac[N];

int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	scanf ("%s", s + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; ++ i) fac[i] = fac[i - 1] * i % 998244353;
	for (int i = 1; i <= n; ++ i) scanf ("%d", &c[i]);
	for (int i = 1; i <= n; ++ i) a[i] = i;
	bool f = true;
	for (int i = 1; i <= n; ++ i) {
		if (s[i] != '1') f = false;
	}
	if (f) {
		printf ("%lld\n", fac[n]);
		return 0;
	}
	do {
		int k = 0, sum = 0;
		for (int i = 1; i <= n; ++ i) {
			if (k >= c[a[i]]) {
				++ k;
				continue;
			}
			if (s[i] == '1') ++ sum;
			if (s[i] == '0') ++ k;
		}
		ans = (ans + (sum >= m)) % 998244353;
	}while (next_permutation (a + 1, a + n + 1));
	printf ("%lld\n", ans);
	return 0;
}
