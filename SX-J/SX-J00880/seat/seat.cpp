#include <bits/stdc++.h>
using namespace std;

int a[10100];

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	int l, h = 1, m, n, y, f = 0, fd = 0;
	cin >> m >> n;
	l = m, fd = n * m - n;
	for (int i = 0; i < m * n; i++)
		cin >> a[i];
	y = a[0];
	sort(a, a + n *m);
	for (int i = 0; i < m / 2; i++) {
		for (int j = n * m; j < fd; j--) {
			if (a[j] > y) {
				h++;
				f++;
			} else {
				cout << l << " " << h;
				return 0;
			}
		}
		if (a[h + 1] > y)
			l--;
		else {
			l--;
			break;
		}
		fd = fd - n;
		f += 2;
		for (int q = fd; q < f; q--) {
			if (a[q] > y) {
				h--;
				f++;
				cout << h << " ";
			}  else {
				cout << l << " " << h;
				return 0;
			}
		}
	}
	cout << l << " " << h;
	return 0;
}