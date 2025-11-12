#include <bits/stdc++.h>
using namespace std;
long long n, m, a, x, s, c, r;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a;
	for (int i = 1; i < n * m; i++) {
		cin >> x;
		if (x > a) {
			s++;
		}
	}
	s++;
	r = ceil(s * 1.0 / n );
	if (r % 2 == 0) {
		if (s % n != 0)
			c = n - s % n + 1;
		else
			c = 1;
	} else {
		if (s % n != 0)
			c = s % n;
		else
			c = n;
	}
	cout << r << " " << c;
	return 0;
}