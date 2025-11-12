#include <bits/stdc++.h>
using namespace std;
long long n, m, d, a[504], mod = 998244353, ans;
string h;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> h;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i > 0; i--) {
		ans = (ans *i) / mod;
	}
	cout << ans;
	return 0;
}