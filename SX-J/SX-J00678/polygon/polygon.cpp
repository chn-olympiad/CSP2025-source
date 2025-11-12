#include <bits/stdc++.h>
using namespace std;
int a[5010];
int b[5010];
int n;
long long ans = 0;

void dfs(int now, int cnt) {
	if (now == n + 1) {
		int sum = 0, mx = 0;
		for (int i = 1; i < cnt; i++) {
			sum += a[b[i]];
			mx = max(mx, a[b[i]]);
		}
		if (sum > mx * 2 && cnt - 1 >= 3) {
			ans++;
		}
		return ;
	}
	b[cnt] = now;
	dfs(now + 1, cnt + 1);
	dfs(now + 1, cnt);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	dfs(1, 1);
	printf("%lld", ans);
	return 0;
}
