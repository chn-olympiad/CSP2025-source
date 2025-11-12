#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", " w", stdout);
	int n, m;
	cin >> n >> m;
	int e = n * m;
	for (int i = 1; i <= e; i++) {
		cin >> a[i];
	}
	int q = a[1], w = e;
	sort(a + 1, a + e + 1   );
	for (int i = 1; i <= m; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j <= n; j++) {
				if (a[w] == q) {
					cout << i << " " << j;
					return 0;
				} else
					w--;
			}
		} else {
			for (int j = n; j >= 1; j--) {
				if (a[w] == q) {
					cout << i << " " << j;
					return 0;
				} else {
					w--;
				}

			}
		}

	}
	return 0;
}
