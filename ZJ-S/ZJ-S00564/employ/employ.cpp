#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
string s;
vector<int> c, perm;
int fact(int x) {
	int ans = 1;
	for (int i = 2; i <= x; ++i) ans = 1ll * ans * i % 998244353;
	return ans;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> n >> m;
	cin >> s;
	c.resize(n);
	perm.resize(n);
	iota(perm.begin(), perm.end(), 0);
	for (int &v : c) cin >> v;
	if (m == n) {
		cout << (count(c.begin(), c.end(), 0) || count(s.begin(), s.end(), '0') ? 0 : fact(n)) << '\n';
		exit(0);
	}
	if (n > 10) {
		cout << (n - count(c.begin(), c.end(), 0) < m ? 0 : fact(n)) << '\n';
		exit(0);
	}
	do {
		int failed = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0' || failed >= c[perm[i]]) ++failed;
		}
		if (n - failed >= m) ++ans;
	} while (next_permutation(perm.begin(), perm.end()));
	cout << ans << '\n';
	return 0;
}