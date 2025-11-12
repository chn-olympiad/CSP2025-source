#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t;

bool cmp(int a, int b) {
	return a > b;
}
ll n, st[1100][1100], ans, vis[100010];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 3; ++j) {
				scanf("%lld", &st[i][j]);

			}
			if (st[i][0] > st[i][1] && st[i][0] > st[i][2])
				vis[1]++;
			if (st[i][1] > st[i][0] && st[i][1] > st[i][2])
				vis[2]++;
			if (st[i][2] > st[i][0] && st[i][2] > st[i][1])
				vis[3]++;
			sort(st [i], st[i]  + 3, cmp);
		}
		if (n == 1) {
			ans += st[n][0];
		}
		{
			if (vis[1] <= n / 2 && vis[2] <= n / 2 && vis[3] <= n / 2) {
				for (int i = 1; i <= n; ++i)
					ans += st[i][0];
			} else {
				for (int p = 1; p <= n / 2; ++p) {
					ans += st[p][0];
				}
				for (int p = n / 2; p <= n ; ++p) {
					ans += st[p][1];
				}
			}
		}
		cout << ans << "\n";
		ans = 0;
	}

	return 0;
}