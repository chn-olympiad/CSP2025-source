#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
const int N = 5e3 + 10, mod = 998244353;
int n, a[N], tot, cnt, sum, f[N];
int qpow(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	int t = qpow(a, b >> 1);
	t = t * t % mod;
	if (b % 2) t = t * a % mod;
	return t;
}
signed main() {
	File("polygon");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	int tot = qpow(2, n);
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i ++) {
		sum += a[i];
		for (int j = 1; j <= a[i]; j ++) cnt = (cnt + f[j]) % mod;
		for (int j = min(5000LL, sum); j >= a[i]; j --) f[j] = (f[j] + f[j - a[i]]) % mod;
	}
	cout << (tot - cnt - n - 1 + mod + mod) % mod << endl;
	return 0;
}
