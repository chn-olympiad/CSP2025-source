#include <bits/stdc++.h>
using namespace std;
string s[200][3], t1, t2;
int n, q, ans = 0;
int main() {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
	}
	while (q--) {
		ans = 0;
		cin >> t1 >> t2;
		int len = t1.length();
		for (int i = 1; i <= n; i++) {
			int pos = t1.find(s[i][1]);
			int len2 = s[i][1].length();
			for (int j = pos; j <= len2; j++) t1[j] = s[i][2][j - pos];
			if (t1 == t2) ans++;
		}
		cout << ans << endl;
	}
}