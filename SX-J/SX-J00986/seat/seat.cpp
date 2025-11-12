#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100005], sum, dp[105][105], cnt = 1;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int t = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j == 1) {
				dp[i][j] = a[i];
			} else if (j % 2 == 0) {
				dp[i][j] = a[n * (j - 1) + (n - i + 1)];
			} else if (j % 2 == 1 and j != 1) {
				dp[i][j] = dp[i][j - 1] - 1;
			}
			if (dp[i][j] == t) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
