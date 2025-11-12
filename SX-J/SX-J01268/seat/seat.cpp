#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], k, s;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	k = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == k) {
			s = n * m + 1 - i;
			break;
		}
	}
	if (s % n == 0) {
		cout << s / n << ' ';
		if ((s / n) % 2 == 1)
			cout << n;
		else
			cout << 1;
	} else {
		cout << s / n + 1 << ' ';
		if ((s / n) % 2 == 0)
			cout << s - s / n * n;
		else
			cout << n + 1 - (s - s / n * n);
	}
	return 0;
}
