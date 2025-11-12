#include <bits/stdc++.h>
#define MOD 998244353ll
using namespace std;
long long n, a[5005], f[10005], ans, anv;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	anv = f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 10000; j >= a[i]; j--) {
			f[j] += f[j - a[i]];
			f[j] %= MOD;
			if (j <= a[i] * 2) {
				ans += f[j - a[i]];
				ans %= MOD;
			}
		}
		anv *= 2;
		anv %= MOD;
	}
	anv = anv + MOD - ans - 1;
	anv %= MOD;
	printf("%lld", anv);
	return 0;
}
