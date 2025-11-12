#include <bits/stdc++.h>
using namespace std;
long long n, q, ans;
string s[50000], s1[50000];
string t[50000], t1[50100];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i] >> s1[i];
	for (int i = 1; i <= q; i++) {
		cin >> t[i] >> t1[i];
		if (t[i].size() != t1[i].size()) {
			cout << 0;
			continue;
		}
		for (int j = 1; j <= n; j++) {
			long long start = 0;
			while (t[i].find(s[j], start) != -1) {
				string sss = t[i];
				int w = t[i].find( s[j], start);
				t[i].erase(w, s[j].size());
				t[i].insert(w, s1[j]);
				if (t[i] == t1[i]) {
					ans++;
					start = w + 1;
					t[i] = sss;
				} else {
					t[i] = sss;
					break;
				}

			}
		}
		cout << ans << "\n";
		ans = 0;
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/