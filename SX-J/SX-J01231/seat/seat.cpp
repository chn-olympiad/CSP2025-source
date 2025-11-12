#include <bits/stdc++.h>
using namespace std;

int n, m, a[105], f, f1;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1) {
			f = a[1];
		}
	}
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == f) {
			f1 = i;
			break;
		}
	}
	if (f1 == 1) {
		cout << 1 << " " << f1;
	} else {
		if ((f1 - 1) / n % 2 == 1) {
			cout << (f1 - 1) / n + 1 << " " << abs(f1 % n - 1 - n);
		} else {
			if (f1 % n == 0) {
				cout << (f1 - 1) / n + 1 << " " << n;
			} else {
				cout << (f1 - 1) / n + 1 << " " << f1 % n;
			}
		}
	}

	return 0;
}
