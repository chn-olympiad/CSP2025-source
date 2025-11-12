#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
long long a[N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, c = 1, b = 1, d = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (a[1] < a[i]) {
			d++;
		}
	}
	b = 1 + d / n;
	c = (d + 1) % n;
	if (b % 2 == 0) {
		if (c == 0) {
			c = c + 1;
			cout << b  << " " << c;
			return 0;
		}
		c = n + 1 - c;
		cout << b  << " " << c;
		return 0;
	}
	if (c == 0) {
		c = n;
	}

	cout << b  << " " << c;
	return 0;
}