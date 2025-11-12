#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 50, mod = 998244353;
int n, a[N], vis[N], an[N], ans;

void dfs(int x, int ma, int sum, int y) {
	if (x > 3 && sum > ma * 2) {
		ans++;
		ans %= mod;
	}
	if (x > n)
		return;
	for (int i = y + 1; i <= n; i++) {
		vis[i] = 1;
		dfs(x + 1, max(ma, a[i]), sum + a[i], i);
		vis[i] = 0;
	}
}

int A(int y, int x) {
	int ans = 1;
	for (int i = y; i >= (y - x + 1); i--) {
		ans = ans * i;
		ans = ans % mod;
	}
	return ans ;
}

int c(int y, int x) {
	if (x > y / 2) {
		x = (y - n + 1);
	}
	return (((A(y, x)  + mod + 1) ) % mod *A(x, x)) % mod;
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int Z = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) {
			Z = 1;
		}
	}
	if (n > 20 && !Z) {
		int ans = 0;//20 1048365
		for (int i = 3; i <= n; i++) {
			int sum = 1;
			sum = c(n, i);
			ans = ans + sum;
			ans %= mod;
		}
		cout << ans << endl;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	dfs(1, 0, 0, 0);
	cout << ans % mod;
	return 0;
}