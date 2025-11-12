#include <bits/stdc++.h>
using namespace std;
int a[105];

int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, p, man, hang, lie;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	p = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == p) {
			man = i;
			break;
		}
	}
	if (man == 1) {
		cout << "1 1";
		return 0;
	}
	if (man == n * m) {
		cout << n << " 1";
		return 0;
	}
	if (man % n == 0) {
		lie = man / n;
	} else {
		lie = man / n + 1;
	}
	for (int i = 1; i <= (2 * n); i++) {
		if (man % (2 * n) == i) {
			if (i <= n) {
				hang = i;
			} else {
				hang = 2 * n - i + 1;
			}
			break;
		}
	}
	cout << lie << " " << hang;
	return 0;
}
