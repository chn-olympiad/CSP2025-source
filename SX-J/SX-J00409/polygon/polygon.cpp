#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int a, b[10000], c[10000], d, f;
	cin >> a;
	for (int i = 1; i <= a; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= a; i++) {
		c[i] = b[i];
		if (b[i] > b[i + 1]) {
			b[i + 1] = b[i];
		}
		d = b[i + 1];
	}
	if (a < 3) {
		cout << 0;
	}
	if (a = 3) {
		if (c[1] + c[2] + c[3] > 2 * d) {
			cout << 1;
			else
				cout << 0;
		}
	}
}