#include <bits/stdc++.h>
using namespace std;
int a[110];
int b[11][11];
int R;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	R = a[1];
	sort(a + 1, a + n *m + 1);
	int cnt = n * m;
	for (int i = 1; i <= n; i++) {
		if ((i & 1) == 1) {
			for (int j = 1; j <= m; j++) {
				if (a[cnt--] == R) {
					cout << i << " " << j;
					return 0;
				}
			}
		} else {
			for (int j = m; j >= 1; j--) {
				if (a[cnt--] == R) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
