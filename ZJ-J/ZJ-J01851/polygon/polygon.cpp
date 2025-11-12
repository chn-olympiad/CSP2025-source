#include <bits/stdc++.h>
//#inlcude <bits\stdc++.h>

#define int long long

using namespace std;

const int N = 5e3 + 5, V = 5e3 + 5, mod = 998244353;

int n, a[N], sum, f[N * V], s[N * V];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
//	freopen("polygon.in", "r", stdin);
//	freopen("polygon.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++ )	cin >> a[i], sum += a[i];
	sort(a + 1, a + n + 1);
	s[0] = 1;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = a[i] * 2 + 1; j <= sum; j ++ )
			f[j] = (f[j] + s[j - a[i]]) % mod;
		for (int j = sum; j >= a[i]; j -- )
			s[j] = (s[j] + s[j - a[i]]) % mod;
	}
	int ans = 0;
	for (int i = 1; i <= sum; i ++ )
		ans = (ans + f[i]) % mod;
	cout << ans << '\n';
	return 0;
}
//ni bei pian le
