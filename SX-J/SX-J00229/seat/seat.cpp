#include <bits/stdc++.h>
using namespace std;
int n, m, x, s;
int a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = n * m; i >= 1; i--) {
		if (a[i] == x) {
			s = m * n - i + 1;
			break;
		}
	}

	int k = s / n ;
	if (s % n != 0)
		k = k + 1;
	if (s <= n) {
		cout << k << " " << s;
		return 0;
	}
	int j = s % n;

	if (k == 1) {
		j = n - j;
		cout << j << endl;
	}

	if (k % 2 == 0) {
		j = n - j + 1;
	}
	cout << k << " " << j;
	return 0;
}
