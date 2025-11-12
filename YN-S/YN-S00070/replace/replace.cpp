#include <bits/stdc++.h>
using namespace std;
char rep[1010][2][1000010];

void solve() {
	string a, b;
	cin >> a >> b;
//	for (int i = 1)
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			rep[i][1][j + 1] = s[j];
		}
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			rep[i][2][j + 1] = s[j];
		}
	}
	while (q--) {
		solve();
	}
	return 0;
}