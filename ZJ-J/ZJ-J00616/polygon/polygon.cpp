#include <bits/stdc++.h>
using namespace std;
const int N = 5005, MOD = 998244353;
int n, a[N], ans[N], res;
void dfs(int x, int l, int have) {
	if (have > l) return ;
	if (x == n + 1) {
		if (have < l) return ;
		int s = 0, maxx = 0;
		for (int i = 1; i <= n; i ++) {
			s += ans[i];
			maxx = max(maxx, ans[i]);
		}
		if (s > 2 * maxx) res = (res + 1) % MOD;
		return ;
	}
	ans[x] = a[x]; 
	dfs(x + 1, l, have + 1);
	ans[x] = 0;
	dfs(x + 1, l, have);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int l = 3; l <= n; l ++) dfs(1, l, 0);
	printf("%d", res);
	return 0;
}