#include <bits/stdc++.h>
using namespace std;
string s1[200005], s2[2000005];
int n, q;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		int len = t1.size();
		int left = 0, right = 0;
		int f = 0, g = 0, ans = 0;
		for (int i = 0; i < len; i++) {
			if (t1[i] == t2[i] && left == 0)
				left = i, f++, right = 0;
			if (t1[i] != t2[i] && right == 0)
				right = i, g++, left = 0;
		}
		if (f > 1 || g > 1) {
			cout << "0\n";
			continue;
		}
		for (int i = 0; i <= left; i++) {
			for (int j = right; j < len; j++) {
				for (int k = 1; k <= n; k++) {
					if (t1.substr(i, j - i + 1) == s1[k] && t2.substr(i, j - i + 1) == s2[k]) {
						ans++;
						break;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}