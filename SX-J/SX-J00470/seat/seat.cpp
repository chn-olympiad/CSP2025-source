#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	int R = a[0];
	sort(a, a + n *m);
	for (int i = 0; i < n * m; i++) {
		if (a[i] == R) {
			R = n * m - i;
			break;
		}
	}
	int c;
	if (R % n != 0)
		c = R / n + 1;
	else
		c = R / n;
	int r;
	if (c % 2 == 0) {
		if (R % n == 0)
			r = 1;
		else
			r = n + 1 - R % n;
	} else {
		if (R % n == 0)
			r = n;
		else
			r = R % n;
	}
	cout << c << ' ' << r << endl;
	return 0;
}
