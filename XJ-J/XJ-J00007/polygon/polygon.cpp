#include <algorithm>
#include <iostream>
using namespace std;
const long long MAXN = 5005, mod = 998244353;
long long a[MAXN], sum[MAXN];
long long m[MAXN * MAXN];
long long ans;
int main(void) {
	ios_base :: sync_with_stdio(false);
	cin . tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	m[0] = 1;
	for (int i = 1;i <= n; ++i) {
		sum[i] = (sum[i - 1] + a[i]) % mod;
		for (int j = sum[i - 1];j > a[i]; --j) {
			ans = (ans + m[j]) % mod;
			m[j + a[i]] = (m[j] + m[j + a[i]]) % mod;
		}
		for (int j = a[i];j >= 0;--j)
			m[j + a[i]] = (m[j] + m[j + a[i]]) % mod;
	}
	cout << ans;
	return 0;
}
