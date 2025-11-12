#include <bits/stdc++.h>
using namespace std;
int n, m, b[15][15], r;

struct T {
	int h, g, z;
} a[105];

bool cnt(T x, T y) {
	return x.g > y.g ;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].g ;
		a[i].h = i;
	}
	sort(a + 1, a + n *m + 1, cnt);
	for (int i = 1; i <= n * m; i++) {
		if (a[i].h == 1) {
			r = i;
		}
	}
	int k = r / n, l = r % n;
	if (l == 0) {
		cout << k << " ";
		if (k % 2 == 1) {
			cout << n;
		} else {
			cout << 1;
		}
	} else {
		k++;
		cout << k << " ";
		if (k % 2 == 0) {
			cout << n - l + 1;
		} else {
			cout << l ;
		}
	}
	return 0;
}