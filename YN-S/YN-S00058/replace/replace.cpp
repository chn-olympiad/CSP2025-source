#include <bits/stdc++.h>
using namespace std;
string s1[200010], s2[200010];
long long n, q;
string t1, t2, t;
long long ans;

bool check(long long start, long long k) {
	bool flag = false;
	for (long long i = start, j = 0; j < s1[k].size(); i++, j++) {
		if (t[i] != s1[k][j]) {
			return false;
		}
		if (t[i] != t2[i]) {
			flag = true;
		}
	}
	return flag;
}

bool solve(long long k) {
	t = t1;
	for (long long i = 0; i < t.size(); i++) {
		if (t[i] == s1[k][0] && check(i, k)) {
			for (long long j = i, i1 = 0; i1 < s1[k].size(); i1++, j++) {
				t[j] = s2[k][i1];
			}
			for (long long j = 0; j < t.size(); j++) {
				if (t[j] != t2[j]) {
					return false;
				}
			}
			return true;
		}
	}
	return false;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (long long i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	while (q--) {
		ans = 0;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << "0" << endl;
			continue;
		}
		for (long long i = 1; i <= n; i++) {
			if (solve(i)) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/