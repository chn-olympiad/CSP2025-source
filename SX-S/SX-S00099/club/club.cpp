#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int T, n, ans, a[N][4];

void dfs(int x, int s1, int s2, int s3, int sum) {
	if (x == 0) {
		ans = max(ans, sum);
		return ;
	}
	if (s1 < n / 2)
		dfs(x - 1, s1 + 1, s2, s3, sum + a[x][1]);
	if (s2 < n / 2)
		dfs(x - 1, s1, s2 + 1, s3, sum + a[x][2]);
	if (s3 < n / 2)
		dfs(x - 1, s1, s2, s3 + 1, sum + a[x][3]);
	return ;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			cin >> a[i][1] >> a[i][2] >> a[i][3];
//		printf("\n");
		dfs(n, 0, 0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
