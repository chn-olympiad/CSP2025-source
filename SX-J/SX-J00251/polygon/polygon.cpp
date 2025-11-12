#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005, mod = 998244353;
int n, a[N], f[N], mx, ans;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = a[i] + 1; j <= mx; j++) {
			ans = (ans + f[j]) % mod;
		}
		for (int j = mx; j >= 0; j--) {
			f[min(j + a[i], 5001ll)] = (f[min(j + a[i], 5001ll)] + f[j]) % mod;
		}
		mx = min(mx + a[i], 5001ll);
	}
	cout << ans;
	return 0;
}
