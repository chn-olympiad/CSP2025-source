#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
string s, v, x, y, x1, x2;
map<string, map<string, int>>mp;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		mp[x][y]++;
	}
	for (int i = 1; i <= m; i++) {
		cin >> s >> v;
		for (int j = 0; j < s.size(); j++) {
			for (int k = j; k < s.size(); k++) {
				for (int l = j; l <= k; l++) {
					x1 += s[l];
					x2 += v[l];
				}
				if (mp[x1][x2]) {
					for (int l = 0; l < j; l++) {
						if (s[l] != v[l]) {
							x1 = "";
							x2 = "";
							continue;
						}
					}
					for (int l = k + 1; l < s.size(); l++) {
						if (s[l] != v[l]) {
							x1 = "";
							x2 = "";
							continue;
						}
					}
//					cout << x1 << " " << x2;
					ans += mp[x1][x2];
					x1 = "";
					x2 = "";
				}
				x1 = "";
				x2 = "";
			}
		}
		x1 = "";
		x2 = "";
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
