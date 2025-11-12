#include <bits/stdc++.h>
using namespace std;

int id(int a, int b, int c) {
	int t = max(a, max(b, c));
	if (t == a)
		return 0;
	if (t == b)
		return 1;
	return 2;
}

int T, n;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		if (n == 2) {
			int a, b, c, a1, b1, c1;
			cin >> a >> b >> c >> a1 >> b1 >> c1;
			int x1 = id(a, b, c), x2 = id(a1, b1, c1);
			if (x1 != x2) {
				cout << max(a, max(b, c)) + max(a1, max(b1, c1)) << endl;
			} else {
				if (x1 == 0 && x2 == 0) {
					int maxx = max(b, max(b1, max(c, c1)));
					if (maxx == b) {
						cout << b + a1 << endl;
					} else if (maxx == c) {
						cout << c + a1 << endl;
					} else if (maxx == b1) {
						cout << a + b1 << endl;
					} else if (maxx = c1) {
						cout << a + c1 << endl;
					}
				}
				if (x1 == 1 && x2 == 1) {
					int maxx = max(a, max(a1, max(c, c1)));
					if (maxx == a) {
						cout << a + b1 << endl;
					} else if (maxx == c) {
						cout << c + b1 << endl;
					} else if (maxx == a1) {
						cout << a1 + b << endl;
					} else if (maxx = c1) {
						cout << b + c1 << endl;
					}
				}
				if (x1 == 2 && x2 == 2) {
					int maxx = max(a, max(a1, max(b, b1)));
					if (maxx == a) {
						cout << a + c1 << endl;
					} else if (maxx == b) {
						cout << b + c1 << endl;
					} else if (maxx == b1) {
						cout << b1 + c << endl;
					} else if (maxx = a1) {
						cout << c + a1 << endl;
					}
				}
			}
		}
	}
	return 0;
}