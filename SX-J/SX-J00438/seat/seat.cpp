#include <bits/stdc++.h>
using namespace std;
int a[200];
int n, m, r, id;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	r = a[1];
	for (int i = 1; i < n * m; i++) {
		for (int j = 1; j <= n * m - i; j++) {
			if (a[j] < a[j + 1]) {
				int x = a[j];
				a[j] = a[j + 1];
				a[j + 1] = x;
			}
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r) {
			id = i;
			break;
		}
	}
	if (id <= m) {
		cout << 1 << ' ' << id;
		return 0;
	}
	if (id % m == 0) {
		cout << id / m << ' ';
		if ((id / m % 2) == 0) {
			cout << 1;
		} else {
			cout << m;
		}
	} else {
		cout << id / m + 1 << ' ';
		if ((id / m + 1) % 2 == 0) {
			cout << m + 1 - id % m;
		} else {
			cout << id % m;
		}
		return 0;
	}
	return 0;
}
