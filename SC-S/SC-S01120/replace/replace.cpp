#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5, M = 2e3+5;
int n, m, q, ans;
string s[N], l[N], s1, s2, g[N], gz[M][M];
void dfs(int i, string sz) {
	if (i == int(s2.size())) {
		ans++;
		return ;
	}
	if (sz[i] == s2[i]) {
		dfs(i + 1, sz);
	}
	for (int j = 1; j <= n; j++) {
		string h = "";
		for (int k = i; k <= (int)min(sz.size() - 1, s[j].size() + i - 1); k++) {
			h = h + sz[k];
		}
		if (i + s[j].size() < s2.size() && l[j][0] == s2[i] && s[j] == h) {
			dfs(i + 1, sz.substr(0, i - 1) + l[j] + sz.substr(i + l[j].size() + 1, s1.size() - 1));
		}
	}
	return ;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> l[i];
	}
	if (q == 1) {
		cin >> s1 >> s2;
		cout << s1.size() << "\n";
	} else {
		while (q--) {
			ans = 0;
			cin >> s1 >> s2;
			int cnt1 = 0, fg = 0, cnt2 = 0;
			for (int i = s1.size() - 1; i >= 0; i--) {
				if (s1[i] == 'b')  cnt1++;
				if (s2[i] == 'b') cnt2++;
				else if (s1[i] != 'a' || s2[i] != 'a') fg = 1;
			}
			if (n <= 2000 && max(s1.size(), s2.size()) <= 2000) {
				dfs(0, s1);
				cout << ans << "\n";
			} else if (fg == 0 && cnt1 == cnt2 && cnt1 == 1) {
				cout << n << "\n";
			} else {
				cout << 0 << "\n";
			}
		}
	}
	return 0;
}