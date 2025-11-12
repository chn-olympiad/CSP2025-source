#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[10010];
	int q;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];

	}
	q = a[1];

	sort(a + 1, a + n *m + 1);

	int c = 1, r = 1;
	int p = n * m;
	for (int i = n * m ; i >= 1; i++) {

		if (c % 2 != 0) {



			if (a[p] == q) {

				break;
			} else if (r >= n) {
				c++;
				r = 1;

			}
			r--;


		} else if ( c % 2 == 0) {




			if (a[p] == q) {
				break;
			} else if (r <= 1) {
				c++;
				r = n;

			}
			r++;


		}


		p--;
	}
	cout << c << ' ' << r ;
	return 0;
}
