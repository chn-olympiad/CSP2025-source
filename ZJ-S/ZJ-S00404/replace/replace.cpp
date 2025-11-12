#include<bits/stdc++.h>
using namespace std;
map<string, string> mp;
int n, q;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string x, y;
		cin >> x >> y;
		mp[x] = y;
	}
	while (q --) {
		int ans = 0;
		string mb, x;
		cin >> x >> mb;
		int n1 = x.size();
		int n2 = mb.size();
		x = ' ' + x;
		mb = ' ' + mb;
		if (n1 != n2) {
			cout << "0\n";
			continue;
		}
		for (int i = 1; i <= n1; i++) {
			for (int j = i; j <= n1; j++) {
				string t = x.substr(i, j - i + 1);
				if (mp[t] == "") {
					continue;
				}
				string tt;
				tt = ' ' + x.substr(1, i - 1) + mp[t] + x.substr(j + 1, n1 - j);
				if (i == 1 && j == n) {
					tt = ' ' + mp[t];
				} 
//				cout << tt << "\n";
				if (tt == mb) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}