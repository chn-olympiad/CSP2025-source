#include <bits/stdc++.h>
using namespace std;
int a, b, d[100000], c[500][500], z;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> a >> b;
	for (int i = 1; i <= a * b; i++) {
		cin >> d[i];
	}
	z = d[1];
	sort(d + 1, d + 1 + a *b);
	for (int ob = 1; ob <= a * b; ob++) {
		if (d[ob] == z) {
			if (ob % a == 0) {
				cout << ob / a << " ";
				if ((ob / a) % 2 == 1) {
					cout << a << " ";
				} else {
					cout << 1 << " ";
				}
			} else if (ob % a != 0) {
				cout << ob / b + 1;

				if ((ob / b + 1) % 2 == 1) {
					cout << ob % a + 1 << " ";
				} else {
					cout << a - ob % a + 1 << " ";
				}
			}
			break;
		}
	}
	return 0;
}
