#include <iostream>
int a[500], s[500], c[500];
int n, m, ans;
bool vis[500], flg = 1;
void dfs(int dep) {
	if (dep == n + 1) {
		int unt = 0, rnt = 0;
		for (int i = 1; i <= n; i++) {
			if (unt >= c[a[i]] || s[i] == 0) {
				unt++;
				continue;
			}
			else rnt++;
		}
		if (rnt >= m) {
			ans++;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			a[dep] = i;
			dfs(dep + 1);
			vis[i] = 0;
		}
	}
}
long long fac[505];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%1d", &s[i]);
		flg &= s[i];
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
