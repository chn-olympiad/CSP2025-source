#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, ans;
int a[100005][3];
int cnt[3];
void dfs(int now, ll sum) {
	if (now == n + 1) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 3; i++) {
		if ((cnt[i] + 1) * 2 <= n) {
			cnt[i]++;
			dfs(now + 1, sum + a[now][i]);
			cnt[i]--;
		}
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		dfs(1, 0);
		printf("%lld\n", ans);
		ans = 0;
	}
	return 0;
}

