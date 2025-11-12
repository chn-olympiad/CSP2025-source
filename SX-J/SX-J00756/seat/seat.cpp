#include <bits/stdc++.h>
using namespace std;
long long a[1000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n;
	int c = 1;
	int r = 1;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		sort(a + 2, a + n + 1);
	}

	if (n == 1 && m == 1) {
		cout << c << " " << r;
	}

	else if (n > 1 && m == 1) {
		c = a[n * m] - a[1];
		cout << c << " " << r;
	}

	else if (n == 1 && m > 1) {
		r = a[n * m] - a[1] + 1;
		cout << c << " " << r;
	}

	else if (n > 1 && m > 1) {
		r = a[n * m] - a[1] + 1;
		for (int i = 1; i <= n * m; i++) {
			if (r > m) {
				c++;
				r = (m - (r - m)) + 1;
			}

			if (r <= m) {
				break;
			}
		}
		cout << c << " " << r;
	}
	return 0;
}
