#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int a, b, n = 0, m = 1, x = 0, y = 0;
	cin >> a >> b;
	n = a * b;
	int cj[n];
	for (int i = 0; i < n; i++) {
		cin >> cj[i];
		if (cj[i] > cj[0])
			m++;
	}
	if (m % 2 * a < 5)
		y = m % (2 * a);
	else {
		if (m % a != 0)
			y = 5 - (m % 4);
		else
			y = 1;
	}
	if (m % 4 != 0)
		x = m % 4;
	else
		x = m / 4;
	cout << x << " " << y;
	return 0;

}
