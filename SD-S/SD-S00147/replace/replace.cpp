#include <bits/stdc++.h>
using namespace std;
const int N = 210000;
int n, q, ans, now;
string s[N][2], t[N][2];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	for (int i = 1; i <= q; i++) {
		cin >> t[i][0] >> t[i][1];
		ans = 0;
		for (int j = 1; j <= n; j++) {
			if (s[j][0].size() <= t[i][0].size()) {
				now = 0;
				for (int k = 0; k < (int)t[i][0].size(); k++) {
					if (s[j][0][now] != t[i][0][k] || s[j][1][now] != t[i][1][k]) {
						k -= now;
						now = 0;
						continue;
					}
					now++;
					if (now == (int)s[j][0].size()) {
						for (int l = 0; l < (int)t[i][0].size(); l++) {
							if (t[i][0][l] != t[i][1][l] && (l > k || l <= k - now)) {
								ans--;
								break; 
							}
						}
						k -= now;
						k++;
						now = 0;
						ans++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
