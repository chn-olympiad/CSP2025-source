#include <bits/stdc++.h>
using namespace std;

bool px(long long a, long long b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, a[109], t, s;
	cin >> n >> m;
	for (long long i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	t = a[0];
	sort(a, a + n *m, px);
	for (long long i = 0; i < n * m; i++) {
		if (a[i] == t) {
			s = i + 1;
			break;
		}
	}
	long long c, r;
	if (s % n == 0)
		c = s / n;
	else
		c = s / n + 1;
	if (c % 2 == 1) {
		if (s % n == 0)
			r = n;
		else
			r = s % n;
	} else {
		if (s % n == 0)
			r = 1;
		else
			r = n - s % n + 1;
	}
	cout << c << "¡¡" << r;
}