#include <bits/stdc++.h>
using namespace std;
int n, m, c, k, a[100005], b[100005];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (b[i] == a[1]) {
			if (i % n == 0) {
				c = i / n;
			} else {
				c = i / n + 1;
			}
			if (c % 2 == 0) {
				k = n - i / n + 1;
			} else {
				if (i % n == 0)
					k = n;
				else
					k = 1 + i % n - 1;
			}
		}
	}
	cout << c << ' ' << k;
	return 0;
}
