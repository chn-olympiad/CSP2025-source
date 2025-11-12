#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], b, h, l;
double c;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int z = n * m;
	for (int i = 1; i <= z; i++) {
		cin >> a[i];
	}
	b = a[1];

	sort(a, a + z + 1);
	int j = 1;

	for (int i = z; i > 0; i--) {
		if (b == a[i]) {
			break;
		}
		j++;
	}
	l = j / n;
	c = j * 1.0 / n;
	if (c > l) {
		l++;
	}
	if (l % 2 == 0) {
		h = n - (j + 1) % n - 1 ;
	} else {
		h = j % n;
	}
	if (h == 0) {
		h = n;
	}
	cout << l << ' ' << h;
	return 0;
}