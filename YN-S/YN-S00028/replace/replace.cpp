#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
string s[N], s1[N], t[N], t1[N];
int flag[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> s[i] >> s1[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> t[i] >> t1[i];
	}
	int ans = 0;
	for (int i = 0; i < q; i++) {
		for (int j = 1; j < t[i].size(); j++) {
			if (t[i][j - 1] == t[i][j] && t1[i][j - 1] == t1[i][j]) {
				ans++;
			} else {
				break;
			}
		}
		if (ans + 1 == t[i].size()) {
			flag[i] = 1;
		}
	}
	for (int i = 0; i < q; i++) {
		int cnt = 0;
		if (t[i].size() != t1[i].size()) {
			cout << 0 << '\n';
			continue;
		}
		if (flag[i] == 1) {
			for (int j = 0; j < n; j++) {
				if (t[i] == s[j] && t1[i] == s1[j] && t[i].size() == s[j].size() && t1[i].size() == s1[j].size()) {
					cnt++;
				}
			}
		} else {
			for (int j = 0; j < n; j++) {
				if (t[i].find(s[j]) == t1[i].find(s1[j]) && t[i].find(s[j]) != -1 && t1[i].find(s1[j]) != -1) {
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}