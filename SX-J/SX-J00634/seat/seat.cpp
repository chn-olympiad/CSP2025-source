#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], x, cnt, w, e, sum;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1, a + 1 + n *m);
	for (int i = n * m; i >= 1 ; i--) {
		sum++;
		if (x == a[i]) {
			cnt = sum;
			break;
		}
	}
	w = cnt / n + 1;
	e = cnt % n;
	if (e == 0) {
		e = n;
		w--;
	}

	if (e > n)
		cout << w << " " << 2 * n - e + 1;
	else
		cout << w << " " << e;
}
