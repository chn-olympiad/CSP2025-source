#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], b, c;

bool cmp(int aa, int bb) {
	return bb < aa;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
		if (i == 0) {
			b = a[i];
		}
	}
	sort(a, a + n *m, cmp);
	for (int i = 0; i < n * m; i++) {
		if (b == a[i]) {
			c = i + 1;
			break;
		}
	}
	if (c % (n * 2) == 0) {
		cout << c / n << " " << "1";
		return 0;
	}
	if (c % (n * 2) > n) {
		cout << ceil(c * 1.0 / n) << " " << n - c % n + 1;
		return 0;
	}
	if (c % (n * 2) <= n) {
		cout << ceil(c * 1.0 / n) << " " << c % (n * 2);
	}
	return 0;
}
