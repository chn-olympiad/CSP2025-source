#include <bits/stdc++.h>
using namespace std;
int a[108];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	int s = 1;
	int d = n * m;
	for (int i = 1; i <= d; i++) {
		cin >> a[i];
		int r = a[1];
		if (a[i] > r)
			s++;
	}
	int c, r;
	if (s % n == 0) {
		c = s / n;
		if (c % 2 == 0)
			r = 1;
		else
			r = m;
	} else {
		c = s / n + 1;
		if (c == 1)
			r = s ;
		else if (c % 2 == 0 && c > 1)
			r = n - s % n + 1;
		else
			r = s % n;
	}
	cout << c << " " << r;
	return 0;
}
