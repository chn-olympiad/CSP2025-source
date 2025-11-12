#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	short a[5001], n, s = 0;
	cin >> n;
	for (short i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n == 3) {
		if (a[1] + a[2] > a[3])
			s++;
	} else if (n == 4) {
		if (a[1] + a[2] > a[4])
			s += 2;
		else if (a[1] + a[2] > a[3])
			s++;
		if (a[2] + a[3] > a[4])
			s++;
		if (a[1] + a[2] + a[3] > a[4])
			s++;
	} else {
		s = a[n];
	}
	cout << s;
	return 0;
}