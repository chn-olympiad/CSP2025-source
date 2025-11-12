#include <bits/stdc++.h>
using namespace std;




int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n * m];
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	int  r = a[0];

	sort(a, a + n *m );
	for (int i = 1; i <= n * m; i++) {
		if (a[n * m - i] == r) {
			int h = 0, l = 0;
			if (i % n == 0)
				h = i / n;
			else
				h = i / n + 1;

			if (h % 2 == 1) {
				if (i % n == 0)
					l = n;
				else
					l = i % n;
			} else {
				if (i % n == 0)
					l = 1;
				else
					l = n + 1 - i % n ;
			}

			printf("%d %d", h, l);
			return 0;
		}
	}
}
