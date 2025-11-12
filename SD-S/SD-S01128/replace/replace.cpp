#include<bits/stdc++.h>
using namespace std;

const int N = 1100100;
int n, q;
string s, t;
map<pair<string, string>, int> p;

inline void solve() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		cin >> s >> t;
		p[make_pair(s, t)]++;
	}
	while (q--) {
		cin >> s >> t;
		if (s.size() != t.size()) {
			puts("0");
			continue;
		}
		int sz = s.size();
		int l = 0, r = sz - 1;
		while (s[l] == t[l]) 
			l++;
		while (s[r] == t[r]) 
			r--;
		l--, r++;
		int ans = 0; 
		for (int i = 0; i <= l; i++) {
			string s1 = s.substr(0, r);
			string t1 = t.substr(0, r);
			for (int j = r; j < sz; j++) {
				s1.push_back(s[j]);
				t1.push_back(t[j]);
				ans += p[make_pair(s1, t1)];
			}
		}
		printf("%d\n", ans);
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int t = 1;
//	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
