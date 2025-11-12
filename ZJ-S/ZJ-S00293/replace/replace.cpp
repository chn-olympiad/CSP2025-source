#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
using ll = long long;
using pss = pair<string, string>;
pss a[N + 5];
bool chk(int i, const string& s, const string& t) {
	string tmp;
	for (int j = 0; j + a[i].first.size() - 1 < s.size(); j++) {
		if (s.substr(j, a[i].first.size()) != a[i].first) continue ;
		tmp = s.substr(0, j) + a[i].second;
		if (j + a[i].first.size() < s.size())
			tmp += s.substr(j + a[i].first.size(), s.size() - (j + a[i].first.size()));
		if (tmp == t) return 1;
	}
	return 0;
}
bool CB(const string& s) {
	int ct = 0;
	for (auto& v : s) {
		if (v != 'a' && v != 'b') return 0;
		ct +=(v == 'b');
		if (ct > 1) return 0;
	} return 1;
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
//	bool fl = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
//		if (fl) {
//			fl &= CB(a[i].first);
//			fl &= CB(a[i].second);
//		}
	}
	string s, t;
	while (q--) {
		cin >> s >> t;
		if (s.size() != t.size()) {
			cout << 0 << '\n';
			continue ;
		}
//		if (fl) { fl &= CB(s), fl &= CB(t); }
//		if (fl) {
//			
//			continue ;
//		}
		int ans = 0;
		for (int i = 1; i <= n; i++) ans += chk(i, s, t);
		cout << ans << '\n';
	}
	return 0;
}
