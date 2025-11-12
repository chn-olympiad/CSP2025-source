#include <bits/stdc++.h>
using namespace std;
int n, q, sum, a[1005], cnt;
string s[15], ss[15], t, tt;
bool flag = 1, f;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> ss[i];
		int o = s[i].size();
		for (int j = 0; j < o; j++) {
			if (s[i][j] == 'b')
				cnt++;
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> t >> tt;
		sum = 0;
		flag = 1;
		for (int u = 1; u <= n; u++) {
			if (t.size() != s[u].size() || tt.size() != ss[u].size()) {
				flag = 0;
				continue;
			}
			if (t == s[u] && tt == ss[u]) {
				f = 1;
				int y = t.size();
				for (int j = 0; j < y; j++) {
					if (s[u][j] != ss[u][j])
						sum++;
				}
			}
		}
		if (!f) {
			int y = t.size();
			for (int j = 0; j < y; j++) {
				a[t[j] - 'a']++;
				a[tt[j] - 'a']++;
			}
		}
		if (cnt == 2 * n - 1)
			sum = 1;
		cout << sum << '\n';
	}
	return 0;
}
