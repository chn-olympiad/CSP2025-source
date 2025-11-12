#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int n, m;
int a[N];

int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int s = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	int x = 0;
	for (int i = 1; i <= n * m; i++) {
		x++;
		if (a[i] == s) {
			break;
		}
	}
	for (int i = 1; i <= 2 * n; i++) {
		if (i <= n) {
			for (int j = 1; j <= m; j += 2) {
				if (i + (j - 1) * n == x) {
					cout << j << " " << i;
					return 0;
				}
			}

		} else {
			for (int j = 2; j <= m; j += 2) {
				if ((i - n) + (j - 1) * n == x) {
					cout << j << " " << n - (i - n) + 1;
					return 0;
				}
			}
		}
	}
	return 0;
}