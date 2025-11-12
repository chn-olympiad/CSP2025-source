#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n, m;
char s[505];
ll C[505][505];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		C[i][0] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
	cin >> s;
	bool q = 1;
	for (ll i = 0; i < n; i++) {
		if (s[i] != '1') {
			q = 0;
			break;
		}
	}
	ll cnt = n;
	ll c[505];
	for (ll i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 0) cnt--;
	}
	sort(c + 1, c + n + 1);
	if (cnt < m) {
		cout << 0 << '\n';
	}
	else {
		ll res = 1;
		for (ll i = 2; i <= n; i++) {
			res = res * i % mod;
		}
		cout << res << '\n';
	}
	return 0;
}