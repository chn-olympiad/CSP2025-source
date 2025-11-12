#include <bits/stdc++.h>
using namespace std;
int a[5005], n;
long long ans[5005];
const int mod = 998244353;

void dfs(int cnt, int i, int m) {
	if (m > 2)
		ans[m]++;
	if (m == n) {
		return;
	}
	for (int t = i + 1; t <= n; t++) {
		int cntx = cnt + a[t];
		int x = a[t] + a[t];
		if (m  < 2)
			dfs(cntx, t, m + 1);
		else if (x < cntx)
			dfs(cntx, t, m + 1);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		dfs(a[i], i, 1);
	long long cnt = 0;
	for (int i = 3; i <= n; i++) {
		cnt += ans[i];
		cnt %= mod;
	}
	printf("%lld", cnt + n - 1);
	return 0;
}