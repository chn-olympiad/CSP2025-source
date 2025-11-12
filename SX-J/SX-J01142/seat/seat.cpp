#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1000005], s, b, l, r;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	s = n * m;
	l = 1;
	r = 1;
	for (int i = 1; i <= s; i++) {
		cin >> a[i];
	}
	b = a[1];
	sort(a + 1, a + 1 + s, cmp);
	for (int i = 1; i <= s; i++) {

		if (i / n == 1) {
			if ((i / m ) % 2 == 0)
				r = 1;
			else
				r = 2;
			l = 1 + i % n;
		} else {
			if (i % n == 0)
				l = 1 + i / n;
			if ((i / m ) % 2 == 0)
				r = i % m;
			else
				r = m - i % m;
		}
		if (a[i] == b) {
			cout << l << " " << r;
			return 0;
		}
	}
	return 0;
}

