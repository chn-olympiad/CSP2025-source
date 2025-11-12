#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 998244353ll;
int n, m, c[510], jl = 0;
string s;

ll qpow(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1ll) {
			ans *= a;
			ans %= M;
		}
		a *= a;
		a %= M;
		b >>= 1ll;
	}
	return ans;
}
int main(int argv, char **argc) {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;

	for (int z = 1; z <= n; z++) {
		cin >> c[z];
	}
	sort(c + 1, c + n + 1);

//	for (int z = 1; z <= n; z++) {
//		if (c[z] <= jl)
//			jl++;
//		cout << "::::" << z << ' ' << c[z] << '\n';
//	}
//	n -= jl;
//
//	if (n < m) {
//		cout << 0;
//		return 0;
//	}

	if (s.find('0') == string::npos) {
		ll ans = 1;
		for (int z = 2; z <= n; z++) {
			ans *= ((ll)z);
			ans %= M;
		}
		cout << ans;
		return 0;
	}

	if (m == 1) {
		ll ans = 0;
		if (s.find('1') == string::npos) {
			cout << 0;
			return 0;
		}
		int pos = s.find('1');
//		n += jl;
//		jl = 0;
//		for (int z = 1; z <= n; z++) {
//			if (c[z] <= jl || c[z] < pos)
//				jl++;
//		}
		for (int z = 1; z <= n; z++) {
			if (c[z] > pos) {
				ans++;
				ans %= M;
			}
		}
		for (int z = 2; z <= n - pos - 1; z++) {
			ans *= z;
			ans %= M;
		}
		for (int z = 2; z <= pos; z++) {
			ans *= z;
			ans %= M;
		}
		cout << ans;
		return 0;
	}

	if (m == n) {
		cout << 0;
		return 0;
	}
	return 0;
}
