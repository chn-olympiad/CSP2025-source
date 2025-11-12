#include <bits/stdc++.h>
using namespace std;
int n, q, ans, f, l, r;
string s1[200005], s2[200005], sa, sb;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> sa >> sb;
		f = 0, ans = 0, l = 0, r = 0;
		for (int j = 0; j < int(sa.length()); j++) {
			if (f == 0 && sa[j] != sb[j]) {
				f = 1;
				l = j;
			}
			if (sa[j] != sb[j]) {
				r = j;
			}
		}
		for (int j = 1; j <= n; j++) {
			f = 0;
			if (r - l + 1 <= int(s1[j].length()) && int(sa.length()) >= int(s1[j].length())) {
				for (int k = 0; k < int(sa.length()); k++) {
					if (k > l || k + int(s1[j].length()) < r) {
						continue;
					}
					for (int w = 0; w < int(s1[j].length()); w++) {
						if (w + k >= int(sa.length())) {
							break;
						}
						if (sa[k + w] != s1[j][w] || sb[k + w] != s2[j][w]) {
							break;
						}
						if (w = int(s1[j].length()) - 1) {
							f = 1;
						}
					}
					if (f == 1) {
						ans++;
					}
				}
			}
		}
		cout << ans;
	}
	return 0;
}
