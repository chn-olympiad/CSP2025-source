#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q;
pair<string, string>a[200005];
map<string, string>mp;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i].first >> a[i].second, mp[a[i].first] = a[i].second;
	while (q--) {
		string x, y;
		cin >> x >> y;
		if (x.size() != y.size()) {
			cout << "0\n";
			continue;
		}
		int l, r, ans = 0;
		for (int i = 0; i < x.size(); i++)
			if (x[i] != y[i]) {
				l = i;
				break;
			}
		for (int i = x.size() - 1; i >= 0; i--)
			if (x[i] != y[i]) {
				r = i;
				break;
			}
		for (int op = 0; l >= 0 && r < x.size(); op++, op %= 3) {
			string s1 = x.substr(l, r - l + 1), s2 = y.substr(l, r - l + 1);
			if (mp.count(s1) && s2 == mp[s1])
				ans++;
			if (op == 0)
				l--;
			if (op == 1)
				l++, r++;
			if (op == 2)
				l--;
		}
		cout << ans << "\n";
	}
	return 0;
}