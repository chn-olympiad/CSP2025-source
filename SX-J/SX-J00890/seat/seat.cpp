#include <bits/stdc++.h>
using namespace std;
int a[1010];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("saat.out", "w", stdout);
	int n = 0, m = 0, s = 0, x = 0, y = 0, num = 0;
	cin >> n >> m;
	for (int  i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	s = a[0];
	for ( int i = 0; i < n * m; i++) {
		if (a[i] < a[i + 1]) {
			int h = a[i];
			a[i] = a[i + 1];
			a[i + 1] = h;
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (s == a[i]) {
			num = ++i;
			break;
		}
	}
	x = num % m;
	int y1 = num / m;
	if (y1 % 2 == 1 && x == 0) {
		x = n;
	}
	if (x == 0) {
		x = 1;
	}
	y = num / m ;
	if (y == 0) {
		y = num % m;
	}
	if (num % m != 0) {
		y++;
	}
	cout << x << "¡¡" << y;
	return 0;
}
