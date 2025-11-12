#include <bits/stdc++.h>
using namespace std;
long long a[5005], s[5005], ans, mo = 998244353, n;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	ans = ((((n * (n - 1)) % mo) * (n - 2)) % mo) * (n - 3);
	ans %= mo;
	cout << ans;
}
