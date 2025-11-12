#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int a, b, c = 1, h = 1, l = 1, d, s = 2, r, n;
	cin >> a >> b;
	cin >> r;
	for (int i = 1; i <= a * b - 1; i++) {
		cin >> c;
		if (c > r && s % 2 == 0) { //从上往下
			h = h + 1;

			if (h > a) {
				l = l + 1;

				h = a;
				s = s + 1;


			}
		} else if (c > r && s % 2 != 0) { //从下往上
			h = h - 1;

			if (h == 0) {
				l = l + 1;

				h = 1;
				s = s + 1;

			}
		}
	}
	cout << l << " " << h;
	return 0;
}