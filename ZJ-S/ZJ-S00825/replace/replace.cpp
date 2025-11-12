#include <bits/stdc++.h>
#define sz(x) (int)x.size()
const int N = 2e5 + 6, mod1 = 1e9 + 7, mod2 = 1e9 + 9, base = 23331;
int n, q; std::string s[N][3], t[N][3];
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		std::cin >> s[i][1] >> s[i][2];
	}
	for (int i = 1; i <= q; ++i) {
		std::cin >> t[i][1] >> t[i][2];
		std::vector<int> pos[27];
		for (int j = 0; j < sz(t[i][1]); ++j) {
			pos[t[i][1][j] - 'a'].push_back(j);
		}
		int len = sz(t[i][1]);
		std::vector<int> pre(len + 3, 0), suf(len + 3, 0);
		pre[0] = 1;
		for (int j = 1; j <= len; ++j)
			pre[j] = pre[j - 1] & (t[i][1][j - 1] == t[i][2][j - 1]);
		suf[len + 1] = 1;
		for (int j = len; j >= 1; --j)
			suf[j] = suf[j + 1] & (t[i][1][j - 1] == t[i][2][j - 1]);
		int sum = 0;
		for (int j = 1; j <= n; ++j) {
			std::string tmp = t[i][1];
			int pp = tmp.find(s[j][1]);
			if (pp == -1) continue;
			std::vector<int> p;
			for (auto& k : pos[s[j][1][0] - 'a']) {
				if (k + sz(s[j][1]) - 1 >= sz(t[i][1])) break;
				if (t[i][1].substr(k, sz(s[j][1])) == s[j][1]
					&& t[i][2].substr(k, sz(s[j][2])) == s[j][2]) p.push_back(k);
			}
			for (auto& pos : p) sum += pre[pos] && suf[pos + sz(s[j][1]) + 1];
		}
		std::cout << sum << "\n";
	}
}
