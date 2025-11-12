#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
int cnt;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	int r = a[0];
	sort(a, a + n *m);
	for (int i = n * m - 1; i >= 0; i--) {
		cnt++;
		if (a[i] == r) {
			break;
		}
	}
	int lie = cnt / n;
	if (cnt % n != 0) {
		lie++;
	}
	cout << lie << " ";
	if (lie % 2 == 0) {
		if (cnt % n != 0) {
			cout << n + 1 - cnt % n;
		} else {
			cout << 1;
		}
	}
	if (lie % 2 != 0) {
		if (cnt % n == 0) {
			cout << n;
		} else {
			cout << cnt % n;
		}
	}
	return 0;
}