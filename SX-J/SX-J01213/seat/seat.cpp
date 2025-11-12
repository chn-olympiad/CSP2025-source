#include <bits/stdc++.h>
using namespace std;
int m, n, a[200], htx, f, xb;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	f = n * m;
	for (int i = 1; i <= f; i++)
		cin >> a[i];
	htx = a[1];
	sort(a + 1, a + 1 + f, cmp);
	for (int i = 1; i <= f; i++) {
		if (a[i] == htx) {
			xb = i;
			break;
		}
	}
	if (xb % n == 0) {
		if ((xb / n) % 2 == 0)
			cout << xb / n << " " << 1;
		else
			cout << xb / n << " " << n;
	} else {
		if ((xb / n + 1) % 2 == 0)
			cout << xb / n + 1 << " " << n + 1 - (xb % n);
		else
			cout << xb / n + 1 << " " << xb % n;
	}
	return 0;
}
