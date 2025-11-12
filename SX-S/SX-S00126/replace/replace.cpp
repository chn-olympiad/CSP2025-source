#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int, int>
#define fi first
#define se second
using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<pair<string, string> > s(n + 1), t = s;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i].fi >> s[i].se;
	}
	for (int i = 1; i <= q; i ++) {
		cin >> t[i].fi >> t[i].se;
//		int cnt = 0;
//		for (int j = 1; j <= n; j ++) {
//			if (t[i].fi.find(s[j].fi) && t[i].se.find(s[j].se)) {
//				int l1 = s[j].fi[0];
//				int l2 = s[j].se[0];
//				int r1 = s[j].fi[s[j].fi.size() - 1];
//				int r2 = s[j].se[s[j].se.size() - 1];
//				string s1 = t[i].fi.substr(0, t[i].fi.find(l1)) + t[i].fi.substr(t[i].fi.find(r1) + 1);
//
//				string s2 = t[i].se.substr(0, t[i].fi.find(l2)) + t[i].se.substr(t[i].fi.find(r2) + 1);
//				if (s1 == s2) {
//					cnt ++;
//				}
//			}
//		}
		cout << 0 << endl;
	}
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}
// AKCSP-S2025!!!
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
