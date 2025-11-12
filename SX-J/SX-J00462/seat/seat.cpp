#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1000005], v[1000005], l, b, c, s, j;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	s = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = n * m; i >= 1; i--) {
		j++;
		v[j] = a[i];
	}
	for (int i = 1 ; i <= n * m; i++) {
		if (s == v[i]) {

			if (i % n == 0) {
				b = i / n;
				c = n;
			} else {
				b = i / n + 1;
				c = i % n;
			}
			break;
		}
	}
	cout << b << " " << c;
	return 0;
}
