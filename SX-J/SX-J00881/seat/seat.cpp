#include <bits/stdc++.h>
using namespace std;
int m, n, s;
int sum;
int c, r, xn;
int a[200];


int main() {
	freopen("seat.in", "w", stdin);
	freopen("seat.out", "r", stdout);
	cin >> n >> m;
	sum = n * m;
	for (int i = 1; i <= sum; i++) {
		cin >> a[i];
	}

	s = a[1];

	sort(a + 1, a + sum + 1);
	for (int i = 1; i <= sum; i++) {
		if (a[i] == s)
			xn = sum - i + 1;
	}

	if ((xn % n) == 0)
		c = (xn / n);
	else
		c = (xn / n) + 1;

	if (c % 2 == 1) {
		if (xn % n == 0)
			r = n;
		else
			r = xn % n;
	} else {
		if (xn % n == 0)
			r = 1;
		else
			r = n - (xn % n) + 1;
	}
	cout << c << " " << r;
	return 0;
}










