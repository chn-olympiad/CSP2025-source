#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n, m, a[100000], r, l, h, cnt, nm;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	r = a[0];
	sort(a + 0, a + n *m);
	for (int i = n * m - 1; i >= 0 ; i--) {
		nm++;
		if (a[i] == r) {
			cnt = nm;
			cout << cnt;
		}
	}
	if (cnt % n > 0) {
		if ((cnt / n + 1) % 2 == 1) {
			l = cnt / n + 1;
			h = cnt % n;
		} else {
			l = cnt / n + 1;
			h = n - (cnt % n) + 1;
		}
	} else {
		l = cnt / n;
		h = n;
	}
	cout << l << " " << h;
	return 0;
}
