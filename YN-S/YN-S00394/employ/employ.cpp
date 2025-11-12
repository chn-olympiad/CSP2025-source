#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("employ.in", "r", stdin);
//	freopen("employ.out", "w", stdout);
	int n, m, b[500];
	string a;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	int c = n;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			c--;
		}
		if (b[i] > (n - i)) {
			c--;
		}
	}
	cout << c;

	return 0;
}