#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005], w;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	w = a[0];
	sort(a, a + n *m + 1);
	int sum = 1;
	for (int i = n * m; i > 0 ; i--) {
		int j = sum++;
		if (a[i] == w) {
			if (j == 1) {
				cout << "1 1";
				return 0;
			}
			if (j % n == 0) {
				if ((j / n) % 2 == 0) {
					cout << j / n << " " << 1;
					return 0;
				} else {
					cout << j / n << " " << n;
					return 0;
				}
			} else if (j % n == 1) {
				cout << j % n + 1  << " " << n;
				return 0;
			} else {
				cout << j / n + 1 << " " << j % n + 2;
				return 0;
			}
		}
	}
	return 0;
}
