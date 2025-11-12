#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("culb.out", "w", stdout);
	int t, n, d[101] = {0}, m = 0, sum = 0, a = 0, b = 0, c = 0, q = 0;
	cin >> t >> n;
	if (n % 2 == 0) {
		for (int i = 1; i <= t; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> d[j];
				if (n <= 2) {
					if (d[j] > m) {
						swap(d[j], m);
						sum += m;
					}
					cout << sum << " ";
				} else {
					q = t % 3;
					if (a + t > b && a + t > c) {
						if (d[j] > m) {
							swap(d[j], m);
							sum += m;
							cout << sum << " ";
						}
						if (b + t > a && b + t > c) {
							if (d[j] > m) {
								swap(d[j], m);
								sum += m;
								cout << sum << " ";
							}
						}
						if (c + t > b && c + t > a) {
							if (d[j] > m) {
								swap(d[j], m);
								sum += m;
								cout << sum << " ";
							}

						}
					}

				}
			}
		}
	}
	return 0;
}


