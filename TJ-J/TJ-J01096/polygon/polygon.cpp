#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, ans;
int a[5005];
void dfs(int cnt, int sum, int maxn) {
	if (sum > maxn * 2) ans = (ans + 1) % mod;
	if (cnt == n) return;
	for (int i = cnt + 1; i <= n; i++)
		dfs(i, sum + a[i], max(maxn, a[i]));
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	dfs(0, 0, 0);
	printf("%d", ans % mod);
	return 0;
}

