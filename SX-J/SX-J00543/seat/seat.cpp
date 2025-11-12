#include <bits/stdc++.h>
using namespace std;
int a[110];

bool cmp(int x, int y) {
	return x, y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n, cj, c, r;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	sort(a + m *n, a + m *n + m);
	cj = a[1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (cj (n) == r && cj (m) == c) {
				cout << c << " " << r;
			}
		}
	}
	return 0;
}