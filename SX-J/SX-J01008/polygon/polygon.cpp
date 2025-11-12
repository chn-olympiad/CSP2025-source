#include <bits/stdc++.h>
using namespace std;
int ans, l;
int n;
int a[5005];
int b[5005][5005];

void dfs(int x, int sum, int pos) {
	if (sum >= a[pos] * 2 + 1 && x > 2)
		ans++;
	if (pos == n)
		return ;
	for (int i = pos + 1; i <= n; i++) {
		dfs(x + 1, sum + a[i], i);
	}
}

void sa(int x) {
	b[1][1] = 1;
	for (int i = 2; i <= x; i++) {
		for (int j = 1; j <= i; j++) {
			b[i][j] = b[i - 1][j] + b[i - 1][j - 1];
			b[i][j] %= 998244353;
		}
	}
	for (int i = 4; i <= x; i++) {
		ans += b[x][i];
		ans %= 998244353;
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l |= a[i];
	}
	sort(a + 1, a + n + 1);
	if (l == 1)
		sa(n + 1);
	else
		dfs(0, 0, 0);
	cout << ans;
	return 0;
}