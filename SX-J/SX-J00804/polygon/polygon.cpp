#include <bits/stdc++.h>
using namespace std;
long long n, m, maxs = -1, ans;
long long a[5005], num[5005];

void zzz(int k, int x) {
	if (k == x ) {
		long long s1 = 0;
		for (int i = 1; i <= x; i++) {
			s1 += a[num[i]];
		}
		if (s1 > 2 * a[num[x]]) {
			ans++;
		}
		s1 = 0;
		return ;
	}
	for (int i = num[k] + 1; i <= n; i++) {
		num[k + 1] = i;
		zzz(k + 1, x);
		num[k + 1] = 0;
	}
	return ;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxs = max(maxs, a[i]);
	}
	sort(a + 1, a + n + 1);
	if (n == 3) {
		if (a[1] + a[2] > a[3])
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	if (maxs == 1) {
		long long x = (n*(n - 1) * (n - 2)) / (3 * 2);
		ans += x;
		for (int i = 4; i <= n; i++) {
			x = x * (n - i + 1) / i;
			ans += x;
			ans %= 998244353;
		}
		cout << ans;
		return 0;
	}
	for (int i = 3; i <= n; i++) {
		zzz(0, i);
	}
	cout << ans;
	return 0;
}
