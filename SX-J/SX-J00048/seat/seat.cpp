#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;

int n, m, num, p, a[105], d, c, r;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	p = n * m;
	cin >> num;
	a[0] = num;
	for (int i = 1; i <= p - 1; i++) {
		cin >> a[i];
	}
	sort(a, a + p, cmp);
	for (int i = 0; i < p; i++) {
		if (a[i] == num) {
			d = i + 1;
		}
	}


	if (d % n == 0) {
		c = d / n;
	} else {
		c = d / n + 1;
	}
	if (c % 2 == 0) {
		r = c * n - d + 1;
	} else {
		r = d - n * c + n;
	}
	cout << c << ' ' << r;
	return 0;
}
