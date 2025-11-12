#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 998244353
#define N 5005
int n, a[N], f[N], ans;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n < 3) {
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; ++i) {
		for (int j = a[n]; j >= a[i]; --j)
			(f[j] += f[j - a[i]]) %= MOD;
		for (int j = a[i] - 1; j >= 0; --j)
			(f[j] += f[0] + 1) %= MOD;
		if (i >= 2)
			(ans += f[a[i + 1]]) %= MOD;
	}
	cout << ans << endl;
	return 0;
}
