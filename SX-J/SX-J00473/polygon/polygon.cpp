#include <bits/stdc++.h>
using namespace std;
long long n, a[5010], h, b[5010], ans, v;

void dfs(int k, int l) {
	for (int i = l; i <= n; i++) {
		b[k] = a[i];
		if (k < v)
			dfs(k + 1, i + 1);
		if (k == v) {
			h = 0;
			sort(b + 1, b + 1 + v);
			for (int j = 1; j <= v; j++) {
				h += b[j];
			}
			if (h > b[v] * 2)
				ans++;
		}
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	if (n < 3) {
		printf("%d\n", 0);
		return 0;
	}
	for (int i = 3; i <= n; i++) {
		v = i;
		dfs(1, 1);
	}
	ans = ans % 998244353;
	printf("%lld\n", ans);
	return 0;
}
