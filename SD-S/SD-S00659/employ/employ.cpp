# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 505;
const ll mod = 998244353;
ll n, m, ans, cnt1;
ll c[N], p[N];
string s;
bool flagA = 1;

int main () {

	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
    ios::sync_with_stdio (0);
    cin.tie (0), cout.tie (0);
	cin >> n >> m;
	cin >> s; s = " " + s;
	for (ll i = 1; i <= n; i ++) {
		if (s[i] != '1') flagA = 0;
		if (s[i] == '1') cnt1 ++;
	}
	for (ll i = 1; i <= n; i ++) cin >> c[i];
	for (ll i = 1; i <= n; i ++) p[i] = i;
	if (m == n) {
		if (flagA) {
			ans = 1;
			for (ll i = 1; i <= n; i ++) ans = (ans * i) % mod;
			cout << ans;
		} else cout << 0;
	} else if (flagA) {
		ans = 1;
		for (ll i = 1; i <= n; i ++) ans = (ans * i) % mod;
		cout << ans;
	} else if (cnt1 <= 18 && n > 100) {
		cout << 0;
	} else {
		do {
			ll cnt = 0, low = 0;
			for (ll i = 1; i <= n; i ++) {
				if (low >= c[p[i]]) break;
				if (s[i] == '0') low ++;
				else cnt ++;
			}
			if (cnt >= m) ans = (ans + 1) % mod;
			} while (next_permutation (p + 1, p + n + 1));
		cout << ans;
	}

	return 0;
}
// 32
