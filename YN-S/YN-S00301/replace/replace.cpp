#include <bits/stdc++.h>
using namespace std;
int const N = 2e5 + 10;
int n, q, ans;
string s1[N], s2[N], t1, t2, l1, l2;

int f(int x, int y) {
	string l = t1;
	for (int i = y; i < s1[x].size() + y; i++) {
		if (t1[i] != s1[x][i - y]) {
			return 0;
		}
		l[i] = s2[x][i - y];
	}
	for (int i = 0; i < l.size(); i++) {
		if (t2[i] != l[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	while (q--) {
		cin >> t1 >> t2;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (s1[i].size() <= t1.size())
				for (int j = 0; j <= t1.size() - s1[i].size(); j++) {
					if (f(i, j) == 1) {
						ans++;
					}
				}
		}
		cout << ans << '\n';
	}
	return 0;
}
