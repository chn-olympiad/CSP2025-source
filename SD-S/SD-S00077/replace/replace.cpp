#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q;
string s[N][3], t1, t2;
int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> s[i][1] >> s[i][2];
	while (q--) {
		cin >> t1 >> t2;
		string d1 = t1, d2 = t2;
		if (t1.size() != t2.size()) {
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			t1 = d1, t2 = d2;
			int x = t1.find(s[i][1]), y = t2.find(s[i][2]);
			if (x > t1.size() || y > t2.size() || x != y)
				continue;
			for (int j = x; j <= x + s[i][2].size() - 1; ++j)
				t1[j] = s[i][2][j - x];
			if (t1 == t2)
				++ans;
		}
		cout << ans << endl;
	}
	return 0;
}
