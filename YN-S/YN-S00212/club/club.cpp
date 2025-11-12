#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int t, n, s[4];
int ans = -1, sum;
int a[maxn][4];

void dfs(int x, int y) {

	if (x == n) {
		ans = max(ans, sum);

		return ;
	}
	if (x == 1) {
		sum += a[x][y];
		s[y] = 1;
	}

	for (int i = x + 1; i <= n; ++i) {

		for (int j = 1; j <= 3; ++j) {
			s[j]++;
			if (s[j] > (n / 2)) {
				s[j]--;
				continue;
			}
			sum += a[i][j];
			dfs(i, j);
			sum -= a[i][j];
			s[j]--;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "r", stdout);

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		dfs(1, 1);
		sum = 0;
		s[1] = s[2] = s[3] = 0;
		dfs(1, 2);
		s[1] = s[2] = s[3] = 0;
		sum = 0;
		dfs(1, 3);
		s[1] = s[2] = s[3] = 0;
		sum = 0;
		cout << ans << endl;
		ans = -1;
	}
	return 0;
}