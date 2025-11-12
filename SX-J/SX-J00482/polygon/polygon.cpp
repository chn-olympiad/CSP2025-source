#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, a[5005], f[5005], ans;

int ksm(int d, int z) {
	if (z == 1)
		return d;
	int x = ksm(d, z / 2);
	x = 1LL * x * x % p;
	if (z % 2)
		return x * d;
	return x;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	ans = ksm(2, n);
	ans --;
	ans += p;
	ans %= p;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= a[i]; j++) {
			ans -= f[j];
			ans += p;
			ans %= p;
		}
		for (int j = 5000; j >= a[i]; j--) {
			f[j] += f[j - a[i]];
			f[j] %= p;
		}
	}
	cout << ans;
	return 0;
}