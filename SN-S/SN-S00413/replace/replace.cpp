#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, q;
string s[N][2], t1, t2;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	while (q--) {
		cin >> t1 >> t2;
		int len = t1.size(), ans = 0;
		for (int i = 1; i <= n; i++) {
			if (t1.find(s[i][0]) == -1) {
				continue;
			}
			int l2 = s[i][0].size();
			for (int j = 0; j < len; j++) {
				string sub = t1.substr(j, l2);
				if (sub == s[i][0]) {
					int fl = 1;
					for (int k = 0; k < len; k++) {
						if (k < j) {
							if (t1[k] != t2[k]) {
								fl = 0;
								break;
							}
						} else if (k < j + l2) {
							if (s[i][1][k - j] != t2[k]) {
								fl = 0;
								break;
							}
						} else {
							if (t1[k] != t2[k]) {
								fl = 0;
								break;
							}
						}
					}
					ans += fl;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
