#include <bits/stdc++.h>
using namespace std;
int n, m, a[209], r;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> r;
	for (int i = 1; i < n * m; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n *m, cmp);
	int p = 1;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m; j++) {
				if (r > a[p]) {
					cout << i << " " << j;
					return 0;
				}
				++p;
			}
		} else {
			for (int j = m; j >= 1; j--) {
				if (r > a[p]) {
					cout << i << " " << j;
					return 0;
				}
				++p;
			}
		}
	}
	cout << n << " " << m;
	return 0;
}
