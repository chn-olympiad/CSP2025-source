#include <bits/stdc++.h>
using namespace std;
int a[225];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1)
			x = a[i];
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == x) {
			y = i;
			break;
		}
	}
	int c = ceil(1.0 * y / n);
	cout << c << " ";
	int e;
	if (y % n == 0)
		e = n;
	else
		e = y % n;
	if (c % 2 == 0)
		cout << n - e + 1;
	else
		cout << e;
	return 0;
}