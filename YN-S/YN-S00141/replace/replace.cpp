//cl csp-s T3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 5;
int n, q, vis[N];
map<string, map<string, int>>mp;
string s, ss;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s >> ss;
		mp[s][ss]++;
	}
	while (q--) {
		cin >> s >> ss;
		int m = s.size() - 1;
		int ans = 0;
		for (int i = 0; i <= m; i++) {
			string s1, ss1;
			bool fl = 1;
			for (int j = 0; j < i; j++) {
				if (s[j] != ss[j])
					fl = 0;
			}
			if (!fl)
				break;
			for (int j = m; j >= 0; j--) {
				vis[j] = 0;
			}
			for (int j = m; j >= 0; j--) {
				if (s[j] != ss[j])
					break;
				vis[j] = 1;
			}
			for (int j = i; j <= m; j++) {
				s1 += s[j];
				ss1 += ss[j];
				if (j != m && !vis[j + 1])
					continue;
				ans += mp[s1][ss1];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}