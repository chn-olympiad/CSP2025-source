#include <bits/stdc++.h>
using namespace std;

bool cmp(int i, int j) {
	return i > j;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n * m + 1];
	int s, si;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1)
			s = a[i];
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (s == a[i]) {
			si = i;
			break;
		}
	}
	int lie, hang;
	if (si % n == 0) {
		lie = si / n;
		if (lie % 2 != 0) {
			hang = n;
		} else {
			hang = 1;
		}
	} else {
		lie = si / n + 1;
		if (lie % 2 != 0) {
			hang = si - n * (lie - 1);
		} else {
			hang = n - (si - n*(lie - 1)) + 1;
		}
	}
	cout << lie << ' ' << hang << endl;
	return 0;
}