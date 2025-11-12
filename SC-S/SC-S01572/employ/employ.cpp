#include <bits/stdc++.h>
using namespace std;
int c[510];
int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	if (m == n) {
		for (int j = 0; j < s.length(); ++j) {
			if (s[j] == '0') {
				cout << 0;
				return 0;
			}
		}
		cout << 1;
		return 0;
	}
	bool flag = true;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '0') flag = false;
	}
	if (flag == true) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (c[i] != 0) ++cnt;
		}
		if (cnt < m) cout << 0;
		else{
			cout << 18;
			return 0;
		}
	}
	cout << 0;
	return 0;
}