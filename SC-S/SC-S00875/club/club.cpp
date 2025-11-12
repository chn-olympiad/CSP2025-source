#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int T, n, full, a[N] = {}, b[N] = {}, c[N] = {};
bool b23 = 0, b3 = 0;
long long ans;
void dfs(int q, int anum, int bnum, int cnum, long long sum) {
	if (q > n) {
		ans = max(ans, sum);
		return;
	}
	if (anum < full) {
		dfs(q + 1, anum + 1, bnum, cnum, sum + a[q]);
	}
	if (bnum < full) {
		dfs(q + 1, anum, bnum + 1, cnum, sum + b[q]);
	}
	if (cnum < full) {
		dfs(q + 1, anum, bnum, cnum + 1, sum + c[q]);
	}
}
void mian() {
	scanf("%d", &n);
	full = (n >> 1);
	ans = 0;
	b23 = b3 = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		if (b[i]) {
			b23 = 1;
		}
		if (c[i]) {
			b23 = 1;
			b3 = 1;
		}
	}
	if (!b23) {
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= full; i++) {
			ans += a[i];
		}
		printf("%lld\n", ans);
		return;
	}
	dfs(1, 0, 0, 0, 0);
	printf("%lld\n", ans);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		mian();
	}
	return 0;
}