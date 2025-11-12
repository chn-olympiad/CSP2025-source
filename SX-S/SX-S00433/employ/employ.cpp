#include <bits/stdc++.h>
using namespace std;
long long mo = 998244353;
int c[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, kl = 0;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 0)
			kl++;
	}
	int op = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '0')
			op = 1;
	}
	if (op == 0) {
		long long ans = 1;
		for (int i = n - kl; i >= 1; i--) {
			ans *= i;
			ans %= mo;
		}
		for (int i = kl; i >= 1; i--) {
			ans *= i;
			ans %= mo;
		}
		cout << ans;
	} else {
		cout << "0";
	}
	return 0;
}
