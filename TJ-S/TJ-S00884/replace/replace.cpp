#include <iostream>
#include <string>
#include <cstdio>
#define int long long
using namespace std;
int n, q, ans;
string s1, s2;
string book[200010][3];
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> book[i][1] >> book[i][2];
	while (q--) {
		ans = 0;
		cin >> s1 >> s2;
		for (int i = 1; i <= n; i++) {
			if (s1.size() < book[i][1].size()) continue;
			for (int j = 0; j <= s1.size() - book[i][1].size(); j++) {
				string x = "", y = "", z = "", x_ = "", y_ = "", z_ = "";
				for (int k = 0; k < j; k++) x += s1[k], x_ += s2[k];
				for (int k = j; k < j + book[i][1].size(); k++) y += s1[k], y_ += s2[k];
				for (int k = j + book[i][1].size(); k < s1.size(); k++) z += s1[k], z_ += s2[k];
				if (x == x_ && y == book[i][1] && book[i][2] == y_ && z == z_) ans++;
//				cout << x << ' ' << book[i][2] << ' ' << z << '\n';
//				cout << x_ << ' ' << y_ << ' ' << z_ << "\n\n";
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

