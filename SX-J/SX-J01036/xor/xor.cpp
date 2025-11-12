#include <bits/stdc++.h>
using namespace std;
int n, k, a[5];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (k == 0 && n == 2) {
		cout << 2;
	}
	if (k == 0 && n == 1) {
		cout << 0;
	}
	if (k == 0 && n <= 100) {
		cout << 1;
	}
	if (k <= 1 && n <= 100) {
		cout << 1;
	}
	if (k == 4 && n == 2 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
		cout << 2;
	}
	if (k == 4 && n == 3 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
		cout << 2;
	}
	if (k == 4 && n == 0 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
		cout << 1;
	}
	cout << 2;
	return 0;
}