#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(long long x, long long y) {
	return x > y;
}

long long n, m, h, l, i, R, s, y;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	long long a[n * m];

	for (i = 0; i < n * m; i++) {
		cin >> a[i];
	}

	R = a[0];
	sort(a, a + (n *m), cmp);

	for (i = 0; i < n * m; i++) {
		if (a[i] == R) {
			s = (i + 1) / n;
			y = (i + 1) % n;
			if (y == 0 && s % 2 == 1) {
				h = n;
				l = s;
				break;
			}
			if (y != 0 && (s + 1) % 2  == 1) {
				h = y;
				l = s + 1;
				break;
			}
			if (y == 0 && s % 2 == 0) {
				h = 1;
				l = s;
				break;
			}
			if (y != 0 && (s + 1) % 2 == 0)  {
				h = n - y + 1;
				l = s + 1;
				break;
			}
		}
	}

	cout << l << " " << h;

	fclose(stdin);
	fclose(stdout);

	return 0;
}

