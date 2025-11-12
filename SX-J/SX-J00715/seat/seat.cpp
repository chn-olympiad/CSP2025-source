#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], x, y, z;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == x) {
			y = i % n;
			z = i / n + 1;
			if (y == 0) {
				y = n;
				z--;
			}
			cout << z << " ";
			if ((z) % 2 == 0) {
				cout << n - y + 1 << endl;
			}
			if ((z) % 2 == 1) {
				cout << y << endl;
			}
			break;
		}
	}
	return 0;
}