#include <bits/stdc++.h>
using namespace std;
int c = 0, r = 0, a, b[105], c[105] == 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> c >> r;
	a = c * r;
	for (int i = 1; i <= a; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= a; i++) {
		if (b[i] < b[i + 1]) {
			c[i] == b[i + 1];
		} else {
			c[i] == b[i];
		}
	}
	for (int i = 1; i <= a; i++) {
		if (c[i] == b[1]) {
			for (int j = 1; j <= a; j++) {
				if (c[i] == j * n) {
					cout << j << n;
				} else if (c[i] == j * n + 1) {
					cout << j << n;
				}
			}
		}
		return 0;
	}