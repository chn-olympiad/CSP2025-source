#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int q = n * m;
	for (int i = 1; i <= q; i++)
		cin >> a[i];
	int w = a[1];
	sort(a, a + q + 1);
	int e = q;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			for (int j = m; j >= 1; j--) {
				if (a[e] == w) {
					cout << i << ' ' << j;
					return 0;
				}
				e--;
			}
		} else {
			for (int j = 1; j <= m; j++) {
				if (a[e] == w) {
					cout << i << ' ' << j;
					return 0;
				}
				e--;
			}
		}

	}
	return 0;
}
