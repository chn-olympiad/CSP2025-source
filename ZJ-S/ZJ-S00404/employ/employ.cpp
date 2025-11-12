#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, m, ans = 1;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	if (m == 1) {
		cout << n;
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		ans *= (n - i + 1);
		ans /= i;
		ans %= mod;
	}
	cout << ans % mod;
	return 0;
}
