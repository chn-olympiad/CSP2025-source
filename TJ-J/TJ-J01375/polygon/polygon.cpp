#include <iostream>
#include <cstdio>
using namespace std;
#define int long long
const int maxn = 5e3 + 8, mod = 998244353;
int n, a[maxn], cnt1;
int C(int b, int a) {
	int res1 = 1, res2 = 1;
	for (int i = 2; i <= b; i++)
		res1 = res1 * i % mod;
	for (int i = 2; i <= a; i++) {
		res2 = res2 * i % mod;
	}
	return res1 / res2;
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n < 3) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt1 += (a[i] == 1);
	}
	if (n == 3) {
		int sum = 0, mx = 0;
		for (int i = 1; i <= n; i++) {
			mx = max(mx, a[i]);
			sum += a[i];
		} 
		cout << (sum >= mx * 2);
		return 0;
	}
	else if (cnt1 == n) {
		int ans = 1;
		for (int i = 3; i < n; i++) {
			int tmp = C(n, i) % mod;
			ans = (ans + tmp) % mod;
		}
		cout << ans;
	}
	return 0;
}
