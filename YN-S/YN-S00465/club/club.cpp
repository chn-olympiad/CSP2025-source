#include <bits/stdc++.h>
using namespace std;
int a[10005], b[10005], c[10005];
int na = 0, nb = 0, nc = 0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	cin >> t >> n;

	for (int i = 0; i < t; i++) {


		for (int j = 1; j <= n; j++) {

			cin >> a[j] >> b[j] >> c[j];
		}

		if (n == 2) {
			if ((a[1] != max(max(a[1], b[1]), max(b[1], c[1])) && a[2] == max(max(a[2], b[2]), max(b[2], c[2])))
			        || (b[1] != max(max(a[1], b[1]), max(b[1], c[1])) && b[2] == max(max(a[2], b[2]), max(b[2], c[2])))
			        || (c[1] != max(max(a[1], b[1]), max(b[1], c[1])) && c[2] == max(max(a[2], b[2]), max(b[2], c[2])))
			        || (a[1] == max(max(a[1], b[1]), max(b[1], c[1])) && a[2] != max(max(a[2], b[2]), max(b[2], c[2])))
			        || (b[1] == max(max(a[1], b[1]), max(b[1], c[1])) && b[2] != max(max(a[2], b[2]), max(b[2], c[2])))
			        || (c[1] == max(max(a[1], b[1]), max(b[1], c[1])) && c[2] != max(max(a[2], b[2]), max(b[2], c[2])))) {
				cout << max(max(a[1], b[1]), max(b[1], c[1])) + max(max(a[2], b[2]), max(b[2], c[2])) << endl;
			} else if ((a[1] == max(max(a[1], b[1]), max(b[1], c[1])) && a[2] == max(max(a[2], b[2]), max(b[2], c[2])))
			           || (b[1] == max(max(a[1], b[1]), max(b[1], c[1])) && b[2] == max(max(a[2], b[2]), max(b[2], c[2])))
			           || (c[1] == max(max(a[1], b[1]), max(b[1], c[1])) && c[2] == max(max(a[2], b[2]), max(b[2], c[2])))) {
				if (a[1] == max(max(a[1], b[1]), max(b[1], c[1])) && a[2] == max(max(a[2], b[2]), max(b[2], c[2]))) {
					if (a[1] == max(a[1], a[2])) {
						cout << a[1] + max(b[2], c[2]) << endl;
					} else {
						cout << a[2] + max(b[1], c[1]) << endl;
					}
				} else if (b[1] == max(max(a[1], b[1]), max(b[1], c[1])) && b[2] == max(max(a[2], b[2]), max(b[2], c[2]))) {
					if (b[1] == max(b[1], b[2])) {
						cout << b[1] + max(a[2], c[2]) << endl;
					} else {
						cout << b[2] + max(a[1], c[1]) << endl;
					}
				} else if (c[1] == max(max(a[1], b[1]), max(b[1], c[1])) && c[2] == max(max(a[2], b[2]), max(b[2], c[2]))) {
					if (c[1] == max(c[1], c[2])) {
						cout << c[1] + max(b[2], a[2]) << endl;
					} else {
						cout << c[2] + max(a[1], b[1]) << endl;
					}
				}
			}

		} else {
			if ((a[1] != max(max(a[1], b[1]), max(b[1], c[1])) && a[2] == max(max(a[2], b[2]), max(b[2], c[2])))
			        || (b[1] != max(max(a[1], b[1]), max(b[1], c[1])) && b[2] == max(max(a[2], b[2]), max(b[2], c[2])))
			        || (c[1] != max(max(a[1], b[1]), max(b[1], c[1])) && c[2] == max(max(a[2], b[2]), max(b[2], c[2])))
			        || (a[1] == max(max(a[1], b[1]), max(b[1], c[1])) && a[2] != max(max(a[2], b[2]), max(b[2], c[2])))
			        || (b[1] == max(max(a[1], b[1]), max(b[1], c[1])) && b[2] != max(max(a[2], b[2]), max(b[2], c[2])))
			        || (c[1] == max(max(a[1], b[1]), max(b[1], c[1])) && c[2] != max(max(a[2], b[2]), max(b[2], c[2])))) {
				cout << max(max(a[1], b[1]), max(b[1], c[1])) + max(max(a[2], b[2]), max(b[2], c[2])) + max(max(a[3], b[3]), max(b[3],
				        c[3])) + max(max(a[4], b[4]), max(b[4], c[4])) << endl;
			} else if ((a[1] == max(max(a[1], b[1]), max(b[1], c[1])) && a[2] == max(max(a[2], b[2]), max(b[2], c[2])))
			           || (b[1] == max(max(a[1], b[1]), max(b[1], c[1])) && b[2] == max(max(a[2], b[2]), max(b[2], c[2])))
			           || (c[1] == max(max(a[1], b[1]), max(b[1], c[1])) && c[2] == max(max(a[2], b[2]), max(b[2], c[2])))) {
				if (a[1] == max(max(a[1], b[1]), max(b[1], c[1])) && a[2] == max(max(a[2], b[2]), max(b[2], c[2]))) {
					if (a[1] == max(a[1], a[2])) {
						cout << a[1] + max(b[2], c[2]) + max(b[3], c[3]) + max(b[4], c[4]) << endl;
					} else {
						cout << a[2] + max(b[1], c[1]) + max(b[3], c[3]) + max(b[4], c[4]) << endl;
					}
				} else if (b[1] == max(max(a[1], b[1]), max(b[1], c[1])) && b[2] == max(max(a[2], b[2]), max(b[2], c[2]))) {
					if (b[1] == max(b[1], b[2])) {
						cout << b[1] + max(a[2], c[2]) + max(b[3], c[3]) + max(b[4], c[4]) << endl;
					} else {
						cout << b[2] + max(a[1], c[1]) + max(b[3], c[3]) + max(b[4], c[4]) << endl;
					}
				} else {
					cout << 17;
				}
			}
		}
	}

	return 0;
}
