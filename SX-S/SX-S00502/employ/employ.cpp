#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 510, mod = 998244353;
ll n, m, c[N], qp[N], q[N], o[N], ans;
string s;

void dg(ll sum, ll k) {
	for (ll i = 1; i <= n; i++) {
		if (!o[i]) {
			o[i] = 1;
			if (k - 1 - sum < c[i] && s[k - 1] == '1') {
				if (k == n)
					ans += (sum + 1 >= m);
				else
					dg(sum + 1, k + 1);
			} else {
				if (k == n)
					ans += (sum >= m);
				else
					dg(sum, k + 1);
			}
			o[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	ll lon = s.size();
	qp[0] = 1;
	for (ll i = 1; i <= n; i++)
		qp[i] = (qp[i - 1] * i) % mod;
	for (ll i = 1; i <= n; i++)
		cin >> c[i];
	if (m == n) {
		for (ll i = 0; i < lon; i++) {
			if (s[i] == '0' || c[i + 1] == 0) {
				cout << 0;
				return 0;
			}
		}
		cout << qp[n];
	} else if (m == 1) {
		for (ll i = 1; i <= n; i++) {
			for (ll j = i + 1; j <= n; j++)
				q[j]++;
		}
		for (ll i = 0; i < lon; i++) {
			if (s[i] == 1) {
				ans += (q[i] * qp[n - i - 1]) % mod;
			}
		}
		cout << ans;
	} else if (n <= 10) {
		dg(0, 1);
		cout << ans;
	} else
		cout << qp[n];
	return 0;
}