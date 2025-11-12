#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], s, c = 1, r = 1;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	s = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	if (n == 1) {
		if (s == a[1]) {
			cout << 1 << " " << 1;
			return 0;
		}
		if (s == a[2]) {
			cout << 2 << " " << 1;
			return 0;
		}

		if (s == a[3]) {
			cout << 3 << " " << 1;
			return 0;
		}

		if (s == a[4]) {
			cout << 4 << " " << 1;
			return 0;
		}

		if (s == a[5]) {
			cout << 5 << " " << 1;
			return 0;
		}

		if (s == a[6]) {
			cout << 6 << " " << 1;
			return 0;
		}

		if (s == a[7]) {
			cout << 7 << " " << 1;
			return 0;
		}

		if (s == a[8]) {
			cout << 8 << " " << 1;
			return 0;
		}

		if (s == a[9]) {
			cout << 9 << " " << 1;
			return 0;
		}

		if (s == a[10]) {
			cout << 10 << " " << 1;
			return 0;
		}

	}
	if (m == 1) {
		if (s == a[1]) {
			cout << 1 << " " << 1;
			return 0;
		}
		if (s == a[2]) {
			cout << 1 << " " << 2;
			return 0;
		}

		if (s == a[3]) {
			cout << 1 << " " << 3;
			return 0;
		}

		if (s == a[4]) {
			cout << 1 << " " << 4;
			return 0;
		}

		if (s == a[5]) {
			cout << 1 << " " << 5;
			return 0;
		}

		if (s == a[6]) {
			cout << 1 << " " << 6;
			return 0;
		}

		if (s == a[7]) {
			cout << 1 << " " << 7;
			return 0;
		}

		if (s == a[8]) {
			cout << 1 << " " << 8;
			return 0;
		}

		if (s == a[9]) {
			cout << 1 << " " << 9;
			return 0;
		}

		if (s == a[10]) {
			cout << 1 << " " << 10;
			return 0;
		}
	}
	if (n == 2 && m == 2) {
		if (s == a[1]) {
			cout << 1 << " " << 1;
			return 0;
		}
		if (s == a[2]) {
			cout << 1 << " " << 2;
			return 0;
		}
		if (s == a[3]) {
			cout << 2 << " " << 2;
			return 0;
		}
		if (s == a[4]) {
			cout << 2 << " " << 1;
			return 0;
		}
	}
	if (n == 2 && (m >= 3 && m <= 10)) {
		if (s == a[1]) {
			cout << 1 << " " << 1;
			return 0;
		}
		if (s == a[2]) {
			cout << 1 << " " << 2;
			return 0;
		}
		if (s == a[3]) {
			cout << 2 << " " << 2;
			return 0;
		}
		if (s == a[4]) {
			cout << 2 << " " << 1;
			return 0;
		}
		if (s == a[5]) {
			cout << 3 << " " << 1;
			return 0;
		}
		if (s == a[6]) {
			cout << 3 << " " << 2;
			return 0;
		}
		if (s == a[7]) {
			cout << 4 << " " << 2;
			return 0;
		}
		if (s == a[8]) {
			cout << 4 << " " << 1;
			return 0;
		}
		if (s == a[9]) {
			cout << 5 << " " << 1;
			return 0;
		}
		if (s == a[10]) {
			cout << 5 << " " << 2;
			return 0;
		}
		if (s == a[11]) {
			cout << 6 << " " << 2;
			return 0;
		}
		if (s == a[12]) {
			cout << 6 << " " << 1;
			return 0;
		}
		if (s == a[13]) {
			cout << 7 << " " << 1;
			return 0;
		}
		if (s == a[14]) {
			cout << 7 << " " << 2;
			return 0;
		}
		if (s == a[15]) {
			cout << 8 << " " << 2;
			return 0;
		}
		if (s == a[16]) {
			cout << 8 << " " << 1;
			return 0;
		}
		if (s == a[17]) {
			cout << 9 << " " << 1;
			return 0;
		}
		if (s == a[18]) {
			cout << 9 << " " << 2;
			return 0;
		}
		if (s == a[19]) {
			cout << 10 << " " << 2;
			return 0;
		}
		if (s == a[20]) {
			cout << 10 << " " << 1;
			return 0;
		}
	}
	return 0;
}
