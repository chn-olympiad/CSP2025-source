#include <bits/stdc++.h>
using namespace std;
int n, q, ans, lmin = 1e5, lmax = 0;
map<string, string>m;
vector<string>v;

inline string replace(string s, string s1, string s2, int k) {
	if (m.find(s) != m.end()) {
		s = m[s];
		if (s != "") {
			k++;
		}
		for (int i = k ; i < s1.size(); i++) {
			s += s1[i];
		}

	}
	return s;
}

inline void dfs(string s1, string s2) {
	for (int y = s1.size(); y > 0; y++) {
		for (int x = s1.size() - y, z = s1.size() - y - x; x >= 0; x--) {
			string s = "", sx = "", sy = "", sz = "", tmp = "";
			for (int i = 0; i < x; i++) {
				sx += s1[i];
			}
			s = sx;
			tmp = s;
			sx = replace(sx, s1, s2, x);
			if (sx == s2)
				ans++;
			for (int i = x; i < s1.size() - z; i++) {
				sy += s1[i];
				tmp += s1[i];
			}
			sy = s + replace(sy, s1, s2, x + y - 1);
			if (sy == s2)
				ans++;
			for (int i = x + y; i < s1.size(); i++) {
				sz += s1[i];
			}
			sz = tmp + replace(sz, s1, s2, x + y + z);
			if (sz == s2)
				ans++;
		}
	}
}

signed main() {
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		m[s1] = s2;
		v.push_back(s1);
	}
	for (int i = 1; i <= q; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		ans = 0;
		dfs(s1, s2);
		cout << ans << endl;
	}

}

