#include <bits/stdc++.h>
using namespace std;
int n, a[5000], e = 0;

void pp(int y, int d) {
	for (int i = y; i < n; i++) {
		if (d > a[i] && d > a[y]) {
			e++;
		}
		if (i != n - 1)
			pp(i + 1, d + a[i]);

	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int y = n - 1; y > i; y--) {
			if (a[y] < a[y - 1])
				swap(a[y], a[y - 1]);
		}
	}
	pp(0, 0);
	cout << e;
	return 0;
}
