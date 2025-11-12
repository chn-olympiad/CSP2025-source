#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], x, y;

bool cmp(int w, int g) {
	return w > g;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "r", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == x) {
			y = i;
			break;
		}
	}
	int b = floor(y / n);
	if (b % 2 == 1) {
		if (y % n == 0)
			cout << b << " " << m;
		else
			cout << b + 1 << " " << m - y % n;
	} else {
		if (y % n == 0)
			cout << b << " " << 1;
		else
			cout << b + 1 << " " << y % n;
	}
	return 0;
}
