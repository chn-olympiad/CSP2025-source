#include"bits/stdc++.h"
using namespace std;
int n, q;
map<string, string>change;
signed main() {
	freopen("replace1.in", "r", stdin);
//	freopen("replace.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		change[s1] = s2;
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		long long ans = 0;
		for (auto t : change) {
			int pos = -1;
			while (1) {
				pos = t1.find(t.first, pos + 1);
				if (pos == -1)
					break;
//				cout<<pos<<' ';
				string x = t1.substr(0, pos);
				string y = t1.substr(pos, t.second.size());
				string z = t1.substr(pos + t.second.size());
//				cout<<x<<','<<y<<','<<z<<'\n';
				if (x + t.second + z == t2)
					ans++;
			}

		}
		cout << ans << '\n';
	}
	return 0;
}