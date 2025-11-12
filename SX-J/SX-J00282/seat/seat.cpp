#include <bits/stdc++.h>
using namespace std;
int n, m, a[150], g;

bool cmp(int c, int b) {
	return c > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int c = n * m;
	for (int i = 1; i <= c; i++)
		cin >> a[i];
	g = a[1];
	sort (a + 1, a + c + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				if (a[n * (i - 1) + j] == g) {
					cout << i << " " << j;
				}
			}
		}
		if (i % 2 == 0) {
			for (int j = n; j >= 1; j--) {
				if (a[n * (i - 1) + (n - j + 1)] == g) {
					cout << i << " " << j;
				}
			}
		}
	}

	return 0;
}