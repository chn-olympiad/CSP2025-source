#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, a[500000], s = 0, x = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (k == 0) {
			if ((a[i] == 0) || (a[i] == a[i - 1])) {
				a[i] = -10;
				s++;
			}
		}
	}
	if (k == 0) {
		cout << s;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		x ^= a[i];
		if (x == k) {
			s++;
			x = 0;
		}
	}
	cout << s;
	return 0;
}