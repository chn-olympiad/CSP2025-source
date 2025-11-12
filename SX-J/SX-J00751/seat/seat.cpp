#include <bits/stdc++.h>
using namespace std;

struct j {
	int cj, bh;
} a[1001];
int m, n;

int cmp(j x, j y) {
	return x.cj > y.cj;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> m >> n;
	int s = m * n;
	for (int i = 1; i <= s; i++) {
		cin >> a[i].cj;
		a[i].bh = i;
	}
	sort(a + 1, a + 1 + s, cmp);
	for (int i = 1; i <= s; i++) {
		if (a[i].bh == 1) {
			if (i % n == 0) {
				cout << i / n  << ' ' << m;
			} else {
				if ((i / n + 1) % 2 != 0) {
					cout << i / n + 1  << ' ' << i % n;
				}
				if ((i / n + 1) % 2 == 0) {
					cout << i / n + 1  << ' ' << m - i % n + 1;
				}
			}

			return 0;
		}
	}
	return 0;
}
