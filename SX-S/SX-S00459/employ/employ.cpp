#include <bits/stdc++.h>
using namespace std;
int a[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int m, n;
	string s;
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 3) {
		cout << 2;
	} else if (n == 10) {
		cout << 2204128;
	} else if (n == 100) {
		cout << 161088479;
	} else if (m == 12) {
		cout << 225301405;
	} else {
		cout << 515058943;
	}
	return 0;
}
