#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
int T, n, ans, a[N][3];

int c[5], num;
void dfs(int x) {
	if (x > n) {
		ans = max(ans, num);
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (c[i] == n / 2) continue;
		c[i]++, num += a[x][i];
		dfs(x + 1);
		c[i]--, num -= a[x][i];
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> T;
	while (T--) {
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> a[i][j];
			}
		}
		
		dfs(1);
		cout << ans << '\n';
	}
	
	return 0;
}
