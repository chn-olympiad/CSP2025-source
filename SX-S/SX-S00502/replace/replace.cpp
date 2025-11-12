#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5+10, mod = 998244353;
ll n, q, sq, qh;

struct node {
	string a, b;
	ll aq, ah, bq, bh;
} s[N], t[N];

node nu(node s) {
	ll o = 1;
	for (ll i = 0; i < s.a.size(); i++) {
		if (s.a[i] == 'b')
			o = 0;
		else {
			if (o == 1)
				s.aq++;
			else
				s.ah++;
		}
	}
	o = 1;
	for (ll i = 0; i < s.b.size(); i++) {
		if (s.b[i] == 'b')
			o = 0;
		else {
			if (o == 1)
				s.bq++;
			else
				s.bh++;
		}
	}
	return s;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (ll i = 1; i <= n; i++) {
		cin >> s[i].a >> s[i].b;
		s[i] = nu(s[i]);
	}
	for (ll i = 1; i <= q; i++) {
		cin >> t[i].a >> t[i].b;
		t[i] = nu(t[i]);
		ll ans = 0;
		for (ll i = 1; i <= n; i++) {
			if (s[i].aq <= t[i].aq && s[i].ah <= t[i].ah && s[i].bq <= t[i].bq && s[i].bh <= t[i].bh) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}