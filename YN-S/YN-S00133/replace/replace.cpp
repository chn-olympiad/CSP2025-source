#include <bits/stdc++.h>
using namespace std;
int n, q, ans;

struct xyz {
	string s1, s2;
};
vector<xyz>s[2500010];

bool check(string s1, string s2) {
	for (int i = 0; i < s1.length(); i++) {

		if (s1[i] != s2[i]) {
			return 0;
		}
	}

	return 1;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {

		string s1, s2;
		cin >> s1 >> s2;
		s[s1.length()].push_back({s1, s2});
	}

	while (q--) {
		ans = 0;
		string s1, s2;
		int l, r;
		cin >> s1 >> s2;

		for (int i = 0; i < s1.length(); i++) {

			if (s1[i] != s2[i]) {
				l = i;
				break;
			}
		}

		for (int i = s1.length() - 1; i >= 0; i--) {

			if (s1[i] != s2[i]) {
				r = i;
				break;
			}
		}

		for (int len = r - l + 1; len <= s1.length(); len++) {

			for (int i = r - len + 1; i + len - 1 < s2.length() && i <= l; i++) {

				int j = i + len - 1;
				string s3, s4;

				for (int k = i; k <= j; k++) {

					s3 += s1[k];
					s4 += s2[k];
				}

				for (int k = 0; k < s[len].size(); k++) {

					if (check(s[len][k].s1, s3)) {
						if (check(s[len][k].s2, s4)) {
							ans++;
						}
					}
				}
			}
		}

		cout << ans << "\n";
	}

	return 0;
}