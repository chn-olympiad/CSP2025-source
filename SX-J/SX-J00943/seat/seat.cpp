#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
int t, l;
int r;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	r = m * n;
	if (n == 1 && m == 1) {
		cout << n << m;
		return 0;
	}
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	t = a[1];
	sort(a + 1, a + 1 + r, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == t) {
			if (i < n) {
				cout << 1 << " " << i;
				return 0;
			}
			if (i % n == 0) {
				if ((i / n) % 2 == 0) {
					cout << i / n << " " << 1;
					return 0;
				} else {
					cout << i / n << " " << n;
					return 0;
				}
			} else {
				if ((i / n) % 2 == 0) {
					cout << (i / n) + 1 << " " << i % n;
					return 0;
				} else {
					for (int k = 1; k <= i; k++) {
						if ((k + i) % n == 1) {
							l = k;
							continue;
						}
					}
					cout << l << " " << i % n + 1;
					return 0;
				}
			}
		}
	}
	return 0;
}
