#include <bits/stdc++.h>
long long ans, k;
int a[5001], n, x;

inline void calc(int start, int len, int sum, int m) {
	if (len > 2 && sum > m * 2) {
		ans++;
		ans %= 998244353;
	}
	if (start == n - 1)
		return;
	calc(start + 1, len + 1, sum + a[start], std::max(m, a[start]));
	calc(start + 1, len, sum, m);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	std::sort(a + 1, a + n + 1);
	if (a[1] == a[n]) {
		k = 0;
		for (int i = 2; i < n; i++) {
			k += (i - 1) * (n - i);
		}
		ans += k;
		ans %= 998244353;
		for (int i = 2; i < n - 1; i++) {
			k -= (n - i) * (n - i - 1) / 2;
			ans += k;
			ans %= 998244353;
		}
	} else
		calc(1, 0, 0, 0);
	printf("%lld", ans);
}