#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 50;
map<string, string> op;
map<string, bool> vis;
int n, t;
string s1, s2, tmp[N];
int ans;

void dfs(string s, int loc) {
	if (s == s2) {
		ans++;
		return;
	}
	if (loc >= s.size())
		return;
//	cout << s << endl;
	dfs(s, loc + 1);
	for (int i = 1; i <= n; i++) {
		while (s1.find(tmp[i], loc) < s1.size()) {
			loc = s1.find(tmp[i], loc);
			string tmp1;
			tmp1 = s.substr(loc, tmp[i].size()), loc++;
//			cout << tmp1 << 1;
			if (vis[tmp1] == 0) {
				vis[tmp1] = 1;
				tmp1 = s;
				tmp1.replace(loc - 1, tmp[i].size(), op[tmp[i]]);
				dfs(tmp1, loc);
			}
		}
	}
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> tmp[i] >> s2;
		op[tmp[i]] = s2;
	}
	for (int i = 1; i <= t; i++) {
		vis.clear();
		ans = 0;
		cin >> s1 >> s2;
		if (s1.size() == s2.size())
			dfs(s1, 0);
		cout << ans << '\n';
	}

	return 0;
}
