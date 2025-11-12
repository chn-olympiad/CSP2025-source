#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, q, l, h;
	cin >> n >> m;
	int a[n * m + 9];
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		q = a[1];
	}
	sort(a + 1, a + m *n + 1);
	for (int i = 1; i <= n * m ; i++) {
		if (a[i] == q) {
			q = i;
		}

	}

	q = m * n + 1 - q;

	l = (q - 1) / n + 1;
	cout << l << " ";
	if (l % 2 == 0) {
		h = (l *m - q) + 1;
	} else {
		h = m - (l *m - q);
	}
	cout << h;

	return 0;
}
