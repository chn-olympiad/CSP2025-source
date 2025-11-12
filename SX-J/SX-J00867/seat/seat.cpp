#include <bits/stdc++.h>
using namespace std;
int a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, c, r, p = 1;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	for (int i = 2; i <= n * m; i++) {
		if (a[1] < a[i]) {
			p++;
		}
	}
	if (p % n == 0) {
		c = p / n;
	} else {
		c = p / n + 1;
	}

	r = p % m;

	cout << c << " " << r;
	return 0;
}