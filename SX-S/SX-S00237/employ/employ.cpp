#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
ll n, m, s[510], c[510];
ll ans, cnt1;
char aaa;
bool flag = true;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> aaa;
		s[i] = (aaa - 48);
		if (s[i] != 1)
			flag = false;
		if (s[i] == 1)
			++cnt1;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	if (m == 1) {
		for (int j = 1; j <= n; ++j) {
			for (int k = j; k <= n && (k - j + 1) <= cnt1; ++k) {
				ll sum = 1;
				for (int o = 1; o <= (k - j + 1); ++o) {
					sum *= o;
				}
				ans += sum % mod;
				ans %= mod;
			}
		}
	} else if (flag == true) {
		for (int i = 1; i <= n; ++i) {
			for (int j = m; j <= n; ++j) {
				ll sum = 1;
				for (int k = 1; k <= (j - i + 1); ++k) {
					sum *= k;
				}
				ans += sum % mod;
				ans %= mod;
			}
		}
	}
	cout << ans % mod;
	return 0;
}