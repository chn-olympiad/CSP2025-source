#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[5005], ans;
void dfs(int i, int sum, int Max, int cnt) {
	if (i > n) {
		if (sum > Max * 2 && cnt >= 3)
			ans = (ans + 1) % mod;
		return ;
	}
	dfs(i + 1, sum + a[i], max(Max, a[i]), cnt + 1);
	dfs(i + 1, sum, Max, cnt);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);	
		maxx = max(maxx, a[i]);	
	}
	if (maxx == 1) {
		long long b = n * (n - 1) * (n - 2) / 6 % mod;
		printf("%lld", b);
		return 0;
	}
	dfs(1, 0, 0, 0);
	printf("%d", ans);
	return 0;
}