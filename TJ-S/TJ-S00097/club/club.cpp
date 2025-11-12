#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
int a[N][4], b[N];
int n, ans;

void dfs(int id, int res, int c1, int c2, int c3) {
	if (id == n + 1) {
		ans = max(ans, res);
		return;
	}
	if (c1 + 1 <= n / 2) dfs(id + 1, res + a[id][1], c1 + 1, c2, c3);
	if (c2 + 1 <= n / 2) dfs(id + 1, res + a[id][2], c1, c2 + 1, c3);
	if (c3 + 1 <= n / 2) dfs(id + 1, res + a[id][3], c1, c2, c3 + 1);
}

bool cmp(int a, int b) {
	return a > b;
}

void solve() {
	int f1 = 1, f2 = 1;
	ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
		b[i] = a[i][1];
		if (a[i][2] != 0) f1 = 0;
		if (a[i][3] != 0) f2 = 0;
	}
	if (f1 == 1 && f2 == 1) {
		sort(b + 1, b + n + 1, cmp);
		for (int i = 1; i <= n / 2; i++) ans += b[i];
	} else {
		dfs(1, 0, 0, 0, 0);
	}
	printf("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
