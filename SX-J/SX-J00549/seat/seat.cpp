#include <bits/stdc++.h>
using namespace std;
int a[110];
int n, m;
int b, d,  r ;
int c ;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "r", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	sort(a, a + n *m);
	for (int i = 0; i < n * m; i++) {
		b++;
	}
	d += b;
	if (b >= n) {
		while (b >= n) {
			b = b - n;
			c += 1;
		}
		if (c % 2 == 0) {
			r += n - b;
		} else {
			r += b + 1;
		}
	} else {
		c += 1;
		r += b;
	}
	cout << c << " " << r << endl;
	return 0;
}