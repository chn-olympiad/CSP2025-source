#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, q, ans;
string s[200005][2], t1, t2;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) cin >> s[i][0] >> s[i][1];
	for (int i = 1; i <= q; i ++) {
		ans = 0;
		cin >> t1 >> t2;
		for (int j = 1; j <= n; j ++) {
			string tmp = t1;
			int st = 0;
			while (1) {
				int pos = tmp.find(s[j][0]);
				if (pos == tmp.npos) break;
				string tmp1 = t1.substr(0, st + pos), tmp2 = t1.substr(st + pos + (int)(s[j][0].size()));
				if (t2 == tmp1 + s[j][1] + tmp2) ans ++;
				tmp = tmp.substr(pos + 1);
				st += pos + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
