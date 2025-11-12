#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int  b[100], c, R, r, w;
	int l, h;
	cin >> c >> r;
	for (int i = 0; i < c * r; i++) {
		cin >> b[i];

	}
	R = b[0];
	for (int i = 0; i < c * r; i++) {
		for (int j = 0; j < i; j++) {
			if (b[i] > b[j])
				swap(b[i], b[j]);
		}
	}
	for (int i = 0; i < c * r; i++) {
		if (b[i] == R)
			w = i + 1;
	}
	l = w / r;
	if (w % r != 0) {
		l++;
	}
	cout << l << " ";
	if (l % 2 == 0) {
		if (w % r == 0)
			cout << 1  ;
		else {
			h = r - w % r;
			cout << h;
		}
	}
	if (l % 2 != 0) {
		if (w % r == 0)
			cout << r  ;
		else {
			h = w % r;
			cout << h;
		}
	}
	return 0;
}