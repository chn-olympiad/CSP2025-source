#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = 1, c[505], mod = 998244353, g;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	long long k = n;

	for (int i = 1; i <= n; i++) {

		cin >> c[i];

		if (c[i] == 0)
			k--;
	}

	for (int i = 1; i <= k; i++) {

		ans = (ans * i) % mod;
	}

	cout << ans % mod;
	return 0;
}