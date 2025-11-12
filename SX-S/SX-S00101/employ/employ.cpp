#include <bits/stdc++.h>
using namespace std;
string s;
int n, m, a[510], die, winner;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (s[i - 1] == 0) {
			die++;
			continue;
		}
		if (die < a[i]) {
			winner++;
			winner %= 998244353;
		}
	}
	if (m == 1) {
		cout << winner;
	} else if (n == m) {
		if (winner >= n) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}
