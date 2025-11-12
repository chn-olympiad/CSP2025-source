#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], x, R, y ;
int c, r ;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m ;
	x = n * m ;
	for (int i = 1 ; i <= x ; i++) {
		cin >> a[i] ;
	}
	R = a[1] ;
	sort(a + 1, a + x + 1);
	for (int i = 1 ; i <= x ; i++) {
		if (a[i] == R) {
			y = x - i + 1 ;
		}
	}
	if (y % n == 0) {
		c = y / n ;
	} else {
		c = y / n + 1 ;
	}
	if (c % 2 == 0) {
		if (y % n == 0) {
			r = 1 ;
		} else {
			r = n - y % n + 1 ;
		}
	} else {
		if (y % n == 0) {
			r = y ;
		} else {
			r = y % n ;
		}
	}
	cout << c << " " << r ;
	return 0;
}
