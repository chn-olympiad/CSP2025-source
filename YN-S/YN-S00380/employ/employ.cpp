#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans = 1, n, m, a[5555];
string s;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	int hh = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0)
			hh++;
	}
	if ((n - hh) < m) {
		cout << "0\n";
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		ans *= i;
		ans %= 998244353;
	}
	int ans1 = 1;
	for (int i = 1; i <= hh; i++) {
		ans1 *= i;
		ans1 %= 998244353;
	}
	if (n - hh - m > 0) {
		int ans2 = 1;
		for (int i = 1; i <= (n - hh - m); i++) {
			ans2 *= i;
			ans2 %= 998244353;
		}
		ans1 = (n - hh - m) * ans1;
		ans1 %= 998244353;
		ans1 *= ans2;
		ans1 %= 998244353;
		ans1 *= ((n - hh - m) + 1);
		ans1 %= 998244353;
		ans *= ans1;
		ans %= 998244353;
	} else {
		ans *= ans1;
		ans %= 998244353;
	}
	cout << ans % 998244353 << "\n";
	return 0;
}//every thing so hard, see u next year
//1111