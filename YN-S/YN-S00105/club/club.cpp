#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int T, n;
ll num[N], ans;
int a[N][4];
int vis[N];
int b[N];

void dfs(int dep, ll sum) {
	if (dep > n) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		for (int j = 1; j <= 3; j++) {
			if (num[j] < (n / 2)) {
				num[j]++;
				vis[i] = 1;
				dfs(dep + 1, sum + a[i][j]);
				num[j]--;
				vis[i] = 0;
			}
		}
	}
}

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		memset(num, 0, sizeof(num));
		scanf("%d", &n);
		bool f = true;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			if (a[i][2] != 0 || a[i][3] != 0)
				f = false;
			b[i] = a[i][1];
		}
		if (f) {
			sort(b + 1, b + n + 1, cmp);
			for (int i = 1; i < (n / 2); i++) {
				ans += b[i];
			}
			printf("%d\n", ans);
		} else {
			dfs(1, 0);
			printf("%d\n", ans);
		}
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}