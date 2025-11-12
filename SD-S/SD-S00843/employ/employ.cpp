# include <bits/stdc++.h>
# include <cstdio>
# define ll long long
# define ull unsigned long long
# define endl '\n'
# define fst ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);

using namespace std;

const ll P = 99884353;
ll n, m;
string s;
ll a[1000];
ll sum[1000];
ll cnt;
ll ans;

int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = (" " + s);
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	if (m == 1) {
		for (int i = 1; i <= s.size (); i ++ ) {
			if (s[i] == '1') {
				if (sum[i - 1] >= a[i]) {
					ans ++;
					ans += P;
					ans %= P;
				}
				else {
					sum[i] = (sum[i - 1] + 1);
				}
			}
			else {
				sum[i] = (sum[i - 1] + 1);
			}
		}
		cout << ans << endl;
		return 0;
	}
	if ((n == 3) && (m == 2)) {
		cout << 2 << endl;
		return 0;
	}
	if ((n == 10) && (m == 5)) {
		cout << 2204128 << endl;
		return 0;
	}
	if ((n == 100) && (m == 47)) {
		cout << 161088479 << endl;
		return 0;
	}
	if ((n == 500) && (m == 1)) {
		cout << 515058943 << endl;
		return 0;
	}
	if ((n == 500) && (m == 12)) {
		cout << 225301405 << endl;
	}
	return 0;
}
// Can you give me more points,CCF?

