#include <bits/stdc++.h>
using namespace std;
long long n, m, a[5000005], r;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		r = a[1];
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r) {
			if (i <= n) {
				cout << 1 << " " << i;
				return 0;
			}
			if (i > n) {
				cout << (i / n) + 1  << " ";
				if ((i / m) % 2 == 0) {
					cout << i % m;
				}
				if ((i / m) % 2 != 0) {
					cout << (i % m) + n - 1;
				}
				return 0;
			}
		}
	}
	return 0;
}
