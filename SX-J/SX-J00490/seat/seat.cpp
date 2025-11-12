#include <bits/stdc++.h>
using namespace std;
int a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int s = a[1];
	int f;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] < a[i + 1]) {
			swap(a[i], a[i + 1]);
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == s) {
			f = i;
			break;
		}
	}
	int c;
	if (f % n == 0) {
		c = f / n;
	} else {
		c = f / n + 1;
	}
	int r;
	if (c % 2 == 0) {
		r = f - m * (c - 1) + 1;
	} else {
		r = f - m * (c - 1);
	}
	cout << c << " " << r;
	return 0;
}