#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n, q;
map<string, string> m;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s, s1;
		cin >> s >> s1;
		m[s] = s1;
	}
	for (int i = 1; i <= q; i++) {
		int ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
			cout << 0;
		else {
			for (auto it : m) {
				int len = it.second.size();
				int y = t1.find(it.first);
				if (y == -1)
					continue;
				string s2 = t1;
				for (int i = y; i < y + len; i++)
					s2[i] = it.second[i - y];
				if (s2 == t2) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}