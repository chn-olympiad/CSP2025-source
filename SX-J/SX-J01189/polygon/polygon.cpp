#include <bits/stdc++.h>
using namespace std;
int n, a[5005], ans = 0, x = 0, xx = 1, b[5005];
bool vis[5005];
int sum = 0;

void dfs(int step) {
	for (int i = b[step - 1] + 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			sum += a[i];
			b[step] = i;
			x++;
			if (x >= 3 && sum > 2 * a[i]) {
				ans++;
			}
			dfs(step + 1);
			vis[i] = 0;
			sum -= a[i];
			x--;
		}
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	dfs(1);
	cout << ans;
	return 0;
}