#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
int a[5100][5100];
int ans[5100][5100];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if (k == 0) {
		memset(a, 0x3f, sizeof a);
		long long aa, b, c;
		for (int i = 1; i <= m; i++) {
			cin >> aa >> b >> c;
			a[aa][b] = c;
			a[b][aa] = c;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)
					continue;
				for (int k = 1; k <= n; k++) {
					if (i == k || j == k)
						continue;
					a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
				}
			}
		}
		cout << a[1][n];
	} else {
		long long aa, b, c;
		long long ans = 0;
		for (int i = 1; i <= m; i++) {
			cin >> aa >> b >> c;
			a[aa][b] = c;
			a[b][aa] = c;
			ans += c;
		}
		cout << ans;
	}

	return 0;
}