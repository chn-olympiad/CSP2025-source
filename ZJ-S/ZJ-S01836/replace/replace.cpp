#include <bits/stdc++.h>
using namespace std;
bool mode = 1;
int n, q;
unordered_map<string, string> s;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string a, b;
		cin >> a >> b;
		s[a] = b;
	}
	while (q--) {
		long long ans = 0;
		string a, b;
		cin >> a >> b;
		if (a.size() != b.size()) {
			cout << 0 << '\n';
			continue;
		}
		int l = 0, r = a.size() - 1;
		while (l < a.size() and a[l] == b[l]) l++;
		while (r >= 0 and a[r] == b[r]) r--;
		if (r < 0) r++;
		for (int i = 0; i <= l; i++) {
			string aa = a.substr(i), bb = b.substr(i);
			for (int j = a.size() - 1; j >= r; j--) {
				ans += (bb == s[aa]);
				aa.erase(aa.end() - 1);
				bb.erase(bb.end() - 1);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
//25-35

