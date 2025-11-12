#include <bits/stdc++.h>
using namespace std;
string s[200005][2], g[2];
int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	for (int f = 1; f <= q; f++) {
		int ans = 0;
		cin >> g[0] >> g[1];
		int l = g[1].size();
		string t[2];
		for (int i = 0; i < l; i++) {
			t[0][i] = g[0][i];
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < s[j][0].size(); k++) {
					while (s[j][0][k] == g[0][i + k]) {
						t[0][i + k] = s[j][1][k];
						k++;
						if (l + k == s[j][0].size()) {
							for (int l = l + k; l <= n; l++) {
								t[0] += s[0][l];
							}
							if (g[1] == t[0]) {
								ans++;
								break;
							}
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}