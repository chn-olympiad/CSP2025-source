#include <bits/stdc++.h>
using namespace std;
int n, q;
string s[201000][3];
string t[201000][3];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
	}

	for (int i = 1; i <= q; i++) {
		int ans = 0;
		cin >> t[i][1] >> t[i][2];
		int user[201000] = {0};
		for (int j = 1; j <= n; j++) {
			string y = s[j][1], y1 = s[j][2];
			string s1 = t[i][1], s2 = t[i][2];
			for (int k = 0; k < s1.size(); k++) {
				int pd = 0;
				if (s1[k] == y[0] && s1[k + y.size() - 1] == y[y.size() - 1] && s2[k] == y1[0]
				        && s2[k + y.size() - 1] == y1[y.size() - 1]) {
					pd ++;
					user[j] ++;
					for (int l = 1; l < y.size() - 1; l++) {
						if (s1[k + l] != y[l] && s2[k + l] != y1[l]) {
							pd = 0;
							break;

						}
					}
					if (user[j] > 2) {
						ans--;
					}
					if (user[j] == 2)
						ans -= 2;
					if (pd == 1 && s1.size() == s2.size()) {
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
