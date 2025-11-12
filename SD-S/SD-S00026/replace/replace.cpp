#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10, Q = 1e6 + 10;

int n, q;
string s[N][3], t[N][3];

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= 2; ++ j)
			cin >> s[i][j];
	for(int i = 1; i <= q; ++ i)
		for(int j = 1; j <= 2; ++ j)
			cin >> t[i][j];
	if(q == 1) {
		cout << 0 << "\n";
		return 0;
	}
	int cnt = 0;
	for(int i = 1; i <= q; ++ i) {
		if(t[i][1].size() != t[i][2].size()) {
			cout << 0 << "\n";
			continue;
		}
		for(int j = 1; j <= n; ++ j) {
			if(s[j][1] == t[i][1] && s[j][2] == t[i][2]) cnt ++;
		}
	}
	cout << cnt << "\n";
	return 0;
}
