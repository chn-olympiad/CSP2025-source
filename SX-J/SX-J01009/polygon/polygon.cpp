#include <bits/stdc++.h>
using namespace std;
int n, a[5005];
bool vis[5005];
long long cnt;

void dfs(int step, long long sum, int maxn, int cntt) {
	if (step > n)
		return;
	if (cntt >= 3) {
		if (sum > 2 * maxn) {
			cnt = (cnt + 1) % 998244353;
		}
	}
	vis[step] = 0;
	dfs(step + 1, sum, maxn, cntt);
	vis[step] = 1;
	maxn = max(maxn, a[step]);
	dfs(step + 1, sum + a[step], maxn, cntt + 1);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	dfs(0, 0, 0, 0);
	printf("%lld", cnt);
	return 0;
}