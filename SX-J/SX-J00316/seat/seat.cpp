#include <bits/stdc++.h>
using namespace std;
int n, m, a[225], x, s, t, y;

bool cmp(int b, int c) {
	return b > c;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	t = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (t == a[i]) {
			s = i;
			break;
		}
	}
	if (s % n != 0)
		y = s / n + 1;
	else
		y = s / n;
	if (y % 2 == 0)
		x = n - (s - (y - 1) * n) + 1;
	else
		x = s - (y - 1) * n;
	cout << y << ' ' << x;
	return 0;
}
