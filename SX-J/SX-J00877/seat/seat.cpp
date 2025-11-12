#include <bits/stdc++.h>
using namespace std;
int a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n, o = 0;
	cin >> n >> m;
	for (int i = 1; i < +n * m; i++) {
		cin >> a[i];
	}
	int x = a[1];
	sort(a + 1, a + n *m + 1);
	int y;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == x) {
			y = n * m - i + 1;
			break;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (m % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				o++;
				if (o == y) {
					cout << i << " " << j;
				}
			}
		}
	}
	return 0;
}
