#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], R, s, sum;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		R = a[1];
	}
	for (int i = 1; i <= n * m; i++) {
		for (int j = 1; j <= n * m; j++) {
			if (a[j] < a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (R == a[i]) {
			s = i - 1;
			break;
		}
	}
	if (s <= n) {
		cout << 1 << " " << s;
		return 0;
	}
	if (s % n == 0) {
		if ((s / n) % 2 == 1) {
			cout << s / n << " " << n;
			return 0;
		} else {
			cout << s / n << " " << 1;
			return 0;
		}
	} else if ((s / n + 1) % 2 == 1) {
		cout << s / n  << " " << s % n;
		return 0;
	} else if ((s / n + 1) % 2 == 0) {
		if (s % n != 1) {
			cout << s / n + 1 << " " << n + 1 - (s % n) ;
			return 0;
		} else {
			cout << s / n + 1 << " " << n;
			return 0;
		}
	}
	return 0;
}
