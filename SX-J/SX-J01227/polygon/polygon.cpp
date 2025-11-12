#include <bits/stdc++.h>
using namespace std;
int n;
int ans, mod = 998244353, gun[5005], c[5005];

void dfs(int a, int num) {
	c[num] = gun[a];
	if (num >= 3) {
		int sum = 0, maxx = 0;
		for (int i = 1; i <= num; i++) {
			sum = (sum + c[i]) % mod;
			maxx = max(maxx, c[i]);
		}
		if (sum > maxx * 2)
			ans = (ans + 1) % mod;
	}
	for (int i = a + 1; i <= n; i++) {
		dfs(i, num + 1);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> gun[i];
	for (int i = 1; i <= n; i++) {
		dfs(i, 1);
	}
	cout << ans % mod;
	return 0;
}
