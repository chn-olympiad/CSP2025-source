#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5, MAX_Q = 2e5;

int n, q;
string s[MAX_N + 1][2];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i][0] >> s[i][1];
		s[i][0] = ' ' + s[i][0];
		s[i][1] = ' ' + s[i][1];
	}
	while (q--) {
		string t1, t2, tmp;
		cin >> t1 >> t2;
		t1 = ' ' + t1;
		t2 = ' ' + t2;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= t1.size() - 1; ++j) {
				if (j + (s[i][0].size() - 1) - 1 > t1.size() - 1) continue;
				bool flag = true;
				for (int k = 1; k <= s[i][0].size() - 1; ++k) {
					if (t1[j + k - 1] != s[i][0][k]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					tmp = t1;
					for (int k = j; k <= j + (s[i][0].size() - 1) - 1; ++k) {
						tmp[k] = s[i][1][k - j + 1];
					}
					if (tmp == t2) ++ans;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
