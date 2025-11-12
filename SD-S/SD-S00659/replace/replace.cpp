# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 2e5 + 5;
ll n, q, ans;
string s1[N], s2[N];

int main () {

	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
    ios::sync_with_stdio (0);
    cin.tie (0), cout.tie (0);
	cin >> n >> q;
	for (ll i = 1; i <= n; i ++) cin >> s1[i] >> s2[i];
	while (q --) {
		ans = 0;
		string s, t; cin >> s >> t;
		for (ll i = 1; i <= 200; i ++) {
			if (s.size () < s1[i].size ()) continue;
			for (ll j = 0; j <= s.size () - s1[i].size (); j ++) {
				string rp = s.substr (j, s1[i].size ());
				// cout << j << " " << rp << " ";
				if (rp == s1[i]) {
					string cz;
					string x = s.substr (0, j);
					string z = s.substr (j + s1[i].size ());
					// cout << x << " " << z << "\n";
					cz = x + s2[i] + z;
					if (cz == t) ans ++;
				}
				// cout << ans << "\n";
			}
		}			
		cout << ans << "\n";
	}
	

	return 0;
}
// 10
