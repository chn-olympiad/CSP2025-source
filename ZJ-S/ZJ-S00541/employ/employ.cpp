#include <iostream>
#include <cstdio>
#define ll long long

using namespace std;

const ll N = 505, mod = 998244353;
char c[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == '0') flag = 0;
	}
	if (flag) {
		ll ans = 1;
		for (ll i = 1; i <= n; i++) {
			ans = ans * i % mod;
		}
		cout << ans;
	} else cout << 0;
	return 0;
}