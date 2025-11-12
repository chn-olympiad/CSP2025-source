#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
const int mod = 998244353;
int n, ans;
int a[N];
void dfs(int x, int num, int w, int maxn) {
	if (x == 0) {
		if (num > 2 * maxn) ans++, ans %= mod;
		return ;
	}
	if (w == n) return ;
	for (int i = w; i <= n; i++) {
		dfs(x - 1, num + a[i], i, max(maxn, a[i]));
	}
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort (a + 1, a + n + 1);
	for (int i = 3; i <= n; i++) {
		dfs(i, 0, 1, 0);
		ans %= mod;
	}
	printf("%lld", ans %= mod);
	return 0;
}