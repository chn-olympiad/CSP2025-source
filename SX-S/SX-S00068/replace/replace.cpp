#include <bits/stdc++.h>
using namespace std;

void file() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
}

using ull = unsigned long long;
int n, q, lim = 0;
ull ha[200005], hb[200005], pw[200005];
string s, t;
unordered_map<ull, int> mp;

int main() {
	file();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s >> t;
		int sz = s.size();
		lim = max(lim, sz);
		if (s == t)
			continue;
		ull HASH = 0;
		for (int i = 0; i < sz; i++)
			HASH = HASH * 131 + s[i];
		for (int i = 0; i < sz; i++)
			HASH = HASH * 131 + t[i];
		mp[HASH]++;
	}
	pw[0] = 1;
	for (int i = 1; i <= 200000; i++)
		pw[i] = pw[i - 1] * 131;
	while (q--) {
		cin >> s >> t;
		if (s.size() != t.size()) {
			cout << 0 << "\n";
			continue;
		}
		int l = 0, r = s.size() - 1;
		for ( ; s[l] == t[l]; l++) ;
		for ( ; s[r] == t[r]; r--) ;
		ha[0] = s[0], hb[0] = t[0];
		for (int i = 1; i < s.size(); i++)
			ha[i] = ha[i - 1] * 131ull + s[i];
		for (int i = 1; i < s.size(); i++)
			hb[i] = hb[i - 1] * 131ull + t[i];
		long long res = 0;
		for (int ll = 0; ll <= l; ll++)
			for (int rr = r; rr - ll + 1 <= lim && rr < s.size(); rr++) {
				ull h1 = ha[rr] - pw[rr - ll + 1] * (ll == 0 ? 0 : ha[ll - 1]);
				ull h2 = hb[rr] - pw[rr - ll + 1] * (ll == 0 ? 0 : hb[ll - 1]);
				res += mp[h1 * pw[rr - ll + 1] + h2];
			}
		cout << res << "\n";
	}
	return 0;
}
