#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, k;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1) {
			k = a[i];
		}
	}
	sort(a + 1, a + n *m + 1);
	for (int i = 1; i <= m * n / 2; i++) {
		int j = m * n - i + 1;
		swap(a[i], a[j]);
	}
	int x, y;
	for (int i = 1; i <= n * m; i++) {
		if (k == a[i]) {
			y = (i + m - 1) / m;
			if (i % n == 0) {
				x = n;
				continue;
			}
			x = i % n;
			if (y % 2 == 0) {
				x = n - x + 1;
			}
		}
	}
	cout << y << " " << x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
