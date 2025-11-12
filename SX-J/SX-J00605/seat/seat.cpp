#include <bits/stdc++.h>
using namespace std;
int n, m, a[1001], t, l;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	l = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == l) {
			t = i;
			break;
		}
	}
	int x, y;
	x = (t % n == 0 ? t / n : t / n + 1);
	if (x % 2 == 1) {
		if (t % n == 0)
			y = n;
		else
			y = t % n;
	} else {
		y = n - t % n + 1;
	}
	cout << x << " " << y;
	return 0;
}