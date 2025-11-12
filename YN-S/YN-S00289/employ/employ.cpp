#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s;
	int n, m;
	unsigned int ans = 1;
	int a = 998244353;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		ans *= i;
		ans %= a;
	}
	cout << ans ;
	return 0;
}