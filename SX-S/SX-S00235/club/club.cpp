#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, y, e, s, yr = 0, er = 0, sr = 0, d = 0;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> y >> e >> s;
			if (yr < n / 2 && er < n / 2 && sr < n / 2) {
				if (y > e && y > s) {
					yr++;
					d = d + y;

				} else if (e > y && e > s) {
					er++;
					d = d + e;

				} else if (s > y && s > e) {
					sr++;
					d = d + s;
				}
			} else if (yr == n / 2 )
				if (y > e && y > s) {
					if (e > s) {
						er++;
						d = d + e;
					} else {
						sr++;
						d = d + s;
					}
				} else if (e > y && e > s) {
					er++;
					d = d + e;

				} else if (s > y && s > e) {
					sr++;
					d = d + s;
				} else if (er == n / 2 )
					if (y > e && y > s) {
						yr++;
						d = d + y;
					} else if (e > y && e > s) {
						if (y > s) {
							sr++;
							d = d + s;
						} else {
							yr++;
							d = d + y;
						}

					} else if (s > y && s > e) {
						sr++;
						d = d + s;
					} else if (sr == n / 2 )
						if (y > e && y > s) {
							yr++;
							d = d + y;
						} else if (e > y && e > s) {
							er++;
							d = d + e;

						} else if (s > y && s > e) {
							if (y > e) {
								yr++;
								d = d + y;
							} else {
								er++;
								d = d + e;

							}
						}
		}
	}
	cout << d << endl;
	return 0;
}
