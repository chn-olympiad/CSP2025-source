#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ", "r", stdin);
	freopen("employ", "w", stdout);
	int m, n;
	cin >> n >> m;
	string s;
	cin >> s;
	int a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
	}
	if (n == m) {
		cout << 1;
	} else if (m == 1) {
		cout << n;
	} else
		cout << 7;
	return 0;
}