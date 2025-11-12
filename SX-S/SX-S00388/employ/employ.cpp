#include <bits/stdc++.h>
using namespace std;
long long n, m, a1, a2, c[505], ans = 1, mo = 998244353;
char a[505];
bool ff, f1[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == '0')
			a1++;
		else
			a2++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = n; i >= 1; i--) {
		ans *= i;
		ans %= mo;
	}
	cout << ans;
}