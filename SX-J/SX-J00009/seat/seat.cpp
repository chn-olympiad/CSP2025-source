#include <bits/stdc++.h>
using namespace std;
int r, a[110], n, m;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r) {
			if (i % n > 0) {
				cout << i / n + 1 << ' ';
				if (i / n % 2 == 0) {
					cout << i % n;
					return 0;
				} else {
					cout << n - i % n + 1;
					return 0;
				}
			} else {
				cout << i / n << ' ';
				if (i / n % 2 == 0) {
					cout << 1;
					return 0;
				} else {
					cout << n;
					return 0;
				}
			}
		}
	}

	return 0;
}
