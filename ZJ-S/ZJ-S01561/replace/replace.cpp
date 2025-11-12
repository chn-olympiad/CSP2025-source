#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
int n, q;
string s1, s2, t1, t2;
vector<pair<string, string>> s[26];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++ ) {
		cin >> s1 >> s2;
		s[s1[0] - 'a'].push_back({s1, s2});
	}
	while (q -- ) {
		ll ans = 0;
		cin >> t1 >> t2;
		vector<string> prefix, endfix;
		string p = "";
		prefix.push_back("");
		for (int i = 0; i < t1.size(); i ++ ) {
			p += t1[i];
			prefix.push_back(p);
		}
		p = "";
		for (int i = t1.size() - 1; i >= 0; i -- ) {
			p = t1[i] + p;
			endfix.push_back(p);
		}
		reverse(endfix.begin(), endfix.end());
		endfix.push_back("");
		for (int i = 0; i < t1.size(); i ++ ) {
			int o = t1[i] - 'a';
			for (auto j: s[o]) {
				s1 = j.fi, s2 = j.se;
				// i ~ i + size - 1
				if (i + s1.size() - 1 < t1.size()) {
					string t3 = prefix[i] + s2 + endfix[i + s1.size()];
					if (t3 == t2) ans ++;
				}
			} 
		}
		if (ans == 0) cout << "0\n";
		else cout << ans << "\n";
	}
	return 0;
}