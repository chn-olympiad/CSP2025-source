#include <bits/stdc++.h>
using namespace std;
int a[5005], c[5005];
long long n, ans, z = 998244353;

long long f(long long x) {
	long long s = 1;
	for (int i = x; i >= 1; i--)
		s = (s * i) % z;
	return s % z;
}

void dfs(int x, int y, int k) {
	if (y == k) {
		int m = 0, s = INT_MIN;
		for (int i = 0; i < y; i++) {
			m += c[i];
			s = max(s, c[i]);
		}
		if (m > s * 2) {
			ans++;
			ans %= z;
		}
	}
	for (int i = x + 1; i <= n; i++) {
		c[y] = a[i];
		dfs(i, y + 1, k);
		c[y] = 0;
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	bool p = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)
			p = 1;
	}
	if (p == 0) {
		long long d = 0;
		for (int i = 3; i <= n; i++) {
			d += (f(n) / (f(n - i) * f(i))) % z;
		}
		cout << d;
		return 0;
	}
	for (int k = 3; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			c[0] = a[i];
			dfs(i, 1, k);
		}
	}
	cout << ans % z;
	return 0;
}