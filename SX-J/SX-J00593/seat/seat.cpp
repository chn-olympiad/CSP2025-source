#include <bits/stdc++.h>
using namespace std;
long long n, m, a[110], c, r;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i * j];
		}
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (a[1] > a[i * j]) {
				c = 1, r = 1;
				cout << c << " " << r;
				return 0;
			} else if (a[1] < a[i * j ]  ) {
				c = i, r = j;
				cout << c << " " << r;
				break;
			}
		}
	}

	return 0;
}
