#include <bits/stdc++.h>
using namespace std;
int a[110];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, i, j;
	cin >> n >> m;
	for (i = 1; i <= n * m; i++)
		cin >> a[i];
	int R = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (j = 1; j <= m; j++) {
				if (a[(i - 1) * n + j] == R) {
					cout << i << " " << j;
					break;
				}
			}
		} else {
			for (j = m; j >= 1; j--) {
				if (a[(i - 1) * n + (m - j + 1)] == R) {
					cout << i << " " << j;
					break;
				}
			}
		}
	}
	return 0;
}
