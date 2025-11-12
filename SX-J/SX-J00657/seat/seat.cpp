#include <bits/stdc++.h>
using namespace std;
long long m, n, s = 1, p, x;

int a[10000];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> m >> n;
	p = m * n;
	for (int i = 1; i <= p; i++) {
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1, a + p + 1, cmp);
	for (int i = 1; i <= p; i++) {
		if (a[i] == x) {
			x = i;
			break;
		}
	}
	while (x - m > 0) {
		x = x - m;
		s++;
	}
	if (s % 2 == 0) {
		cout << s << " " << m - x + 1;
	} else {
		if (x == 0)
			x = m;
		cout << s << " " << x;
	}
	return 0;
}
