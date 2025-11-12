#include <bits/stdc++.h>
using namespace std;
long long a[5005], ans, n;
bool f[5005];
void dfs (long long x, long long ret, long long maxa, long long su) {
	for (int i = 1; i <= n; i++) {
		if (!f[i]) {
			f[i] = 1;
			if (a[i] > maxa) {
				if (su + maxa > 2 * a[i]) {
					if (ret > 2) {
						ans++;
						ans %= 998244353;
					}
				}
				dfs(i, ret + 1, a[i], su + a[i]);
			} else {
				if (su + a[i] > 2 * maxa) {
					if (ret > 2) {
						ans++;
						ans %= 998244353;
					}
				}
				dfs(i, ret + 1, maxa, su + a[i]);
			}
			f[i] = 0;
		}
	}
}
int main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(0, 0, 0, 0);
	cout << ans;
}