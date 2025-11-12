// T3 replace
#include <bits/stdc++.h>
using namespace std;
int n, q; string a[200010], b[200010];
map<string, string> mp;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) 
		cin >> a[i] >> b[i], mp[a[i]] = b[i];
	while (q--) {
		string c, d;
		cin >> c >> d;
		int len = c.size(), ans = 0;
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				bool flag = 0;
				for (int ii = 0; ii < i; ii++) if (c[ii] != d[ii]) { flag = 1; break; }
				for (int ii = j + 1; ii < len; ii++) if (c[ii] != d[ii]) { flag = 1; break; }
				if (flag) continue;
				string tmp1 = "", tmp2 = "";
				for (int ii = i; ii <= j; ii++)
					tmp1 += c[ii], tmp2 += d[ii];
				if (mp[tmp1] == tmp2) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}