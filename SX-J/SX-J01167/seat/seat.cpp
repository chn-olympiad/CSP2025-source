#include <bits/stdc++.h>
using namespace std;
int q, w, e, f;
int a[117];
int c, b, d;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> c >> b;
	for (int i = 1; i <= c * b; i++) {
		cin >> a[i];
	}
	q = a[1];
	sort(a + 1, a + c *b + 1);
	for (int i = 1; i <= c * b; i++) {
		if (a[i] == q) {

			w = c * b - i + 1;
		}
	}
	if (w % c == 0) {
		e = w / c;
	} else {
		e = w / c + 1;
	}
	cout << e << " ";
	if (e % 2 == 1) {
		cout << w - (e - 1)*c;
	} else {
		cout << c - (w - (e - 1)*c) + 1;
	}
	return 0;
}
