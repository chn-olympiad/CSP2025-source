#include <bits/stdc++.h>
using namespace std;
long long n, su, ma, ans;
long long a[5001], b[5001];

void dfs(int d, int nu, int k) {
	b[k] = a[nu];
	su += a[nu];
	ma = max(ma, a[nu]);
	if (k == d) {
		if (ma * 2 <= su) {
			ans++;
		}
	}
	for (long long i = nu; i <= n; i++) {
		dfs(d, nu + 1, k + 1);
		dfs(d, nu + 1, k);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			su = 0;
			dfs(i, j, 1);
		}
	}
	ans = ((ans % 998) % 244) % 353;
	printf("%lld", ans);
	return 0;
}
