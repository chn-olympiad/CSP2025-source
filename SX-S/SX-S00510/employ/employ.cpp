#include <bits/stdc++.h>
using namespace std;
long long n, ans = 1, mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ans = (ans *i) % mod;
	}
	cout << ans;
	return 0;
}
