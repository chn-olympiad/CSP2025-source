#include <bits/stdc++.h>
using namespace std;
string s[200005][2], t[200005][2];

int main() {
	ios::sync_with_stdio(false);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i][0] >> s[i][1];
	for (int i = 1; i <= q; i++) {
		cin >> t[i][0] >> t[i][1];
		int ans = 0;
		for (int j = 0; j < t[i][0].size(); j++) {
			for (int k = 1; k <= n; k++) {
				if (j + s[k][0].size() <= t[i][0].size() && t[i][0].substr(j, s[k][0].size()) == s[k][0]
				        && t[i][0].substr(0, j) + s[k][1] + t[i][0].substr(j + s[k][0].size(), t[i][0].size() - j - s[k][0].size()) == t[i][1])
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}