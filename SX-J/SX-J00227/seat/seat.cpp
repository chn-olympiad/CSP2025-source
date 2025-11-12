#include <bits/stdc++.h>
using namespace std;
int a[105], c, d, l;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, cj;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	cj = a[1];
	sort(a + 1, a + n *m + 1, greater<int>());
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == cj) {
			l = i;
			break;
		}
	}
	c = ceil(l * 1.0 / n);
	if (c == 1)
		d = l;
	else
		d = l % n;

	if (d == 0)
		d = n;
	if (c % 2 == 0) {
		cout <<  c << " " << n - d + 1;
	} else {
		cout << c << " " << d;
	}
	return 0;
}
